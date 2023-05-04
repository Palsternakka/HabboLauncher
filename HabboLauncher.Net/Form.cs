using System.Diagnostics;
using System.IO.Compression;
using System.Runtime.InteropServices;
using System.Text.Json;

namespace HabboLauncher.Net
{
    public partial class Form : System.Windows.Forms.Form
    {
        private string _path;
        private string _site;
        private Details _details;

        public Form()
        {
            _path = Environment.ExpandEnvironmentVariables(@"%AppData%\HabboLauncher");
            _site = "https://YOUR-HOTEL-HERE";

            InitializeComponent();
        }

        private void Form_Load(object sender, EventArgs e)
        {
            try
            {
                var settings = File.ReadAllLines(_path + @"\config.txt");

                if (settings.Length == 2)
                {
                    username.Text = settings[0];
                    password.Text = settings[1];
                    rememberMe.Checked = true;
                }
            }
            catch (DirectoryNotFoundException)
            {
                Directory.CreateDirectory(_path);

                File.Create(Environment.ExpandEnvironmentVariables(_path + @"\config.txt"));
            }
            catch (FileNotFoundException)
            {
                File.Create(Environment.ExpandEnvironmentVariables(_path + @"\config.txt"));
            }

            UnzipProjectors();
        }

        private void UnzipProjectors()
        {
            DeleteDirectoryIfExists(_path + @"\Flash");
            DeleteDirectoryIfExists(_path + @"\Shockwave");

            File.WriteAllBytes(_path + @"\Projectors.zip", Resources.Projectors);

            ZipFile.ExtractToDirectory(_path + @"\Projectors.zip", _path);

            File.Delete(_path + @"\Projectors.zip");
        }

        private void DeleteDirectoryIfExists(string path)
        {
            var directory = new DirectoryInfo(path);

            if (directory.Exists)
            {
                try
                {
                    directory.Delete(true);
                }
                catch (Exception ex) { }
            }
        }

        private void EnterShockwave(object sender, EventArgs e)
        {
            Cursor = Cursors.WaitCursor;

            GetTicket();

            if (_details != null)
            {
                File.WriteAllLines(_path + @"\Shockwave\vars.txt", new string[]
                {
                    _details.Host,
                    _details.ShockwavePort,
                    _details.MusPort,
                    _details.Site,
                    _details.ShockwaveTexts,
                    _details.ShockwaveVariables,
                    _details.ShockwaveDcr,
                    _details.SsoTicket
                });

                var proc = Process.Start(new ProcessStartInfo(_path + @"\Shockwave\Habbo Hotel.exe"));

                ChangeWindowTitle(proc, true);

                Application.Exit();
            }

            Cursor = Cursors.Arrow;
        }

        private void EnterFlash(object sender, EventArgs e)
        {
            Cursor = Cursors.WaitCursor;

            GetTicket();

            if (_details != null)
            {
                var proc = Process.Start(new ProcessStartInfo(_path + @"\Flash\Habbo Hotel.exe")
                {
                    Arguments = $"{_details.FlashSwf}?client.allow.cross.domain=1&client.notify.cross.domain=0&connection.info.host={_details.Host}&connection.info.port={_details.FlashPort}&site.url={_details.Site}/&url.prefix={_details.Site}/&client.reload.url=/disconnected&client.fatal.error.url={_details.Site}/disconnected&client.connection.failed.url={_details.Site}/disconnected&external.variables.txt={_details.FlashVariables}?&external.texts.txt={_details.FlashTexts}?&use.sso.ticket=1&sso.ticket={_details.SsoTicket}&processlog.enabled=1&account_id=1&client.starting=Please wait! Habbo is starting up&flash.client.url={_details.FlashBase}&user.hash=ticket&has.identity=0&flash.client.origin=popup&country_code=US"
                });

                ChangeWindowTitle(proc, false);

                Application.Exit();
            }

            Cursor = Cursors.Arrow;
        }

        private void ChangeWindowTitle(Process proc, bool isShockwave)
        {
            while (proc.MainWindowHandle == new IntPtr(0))
            {
                Thread.Sleep(500);
            }

            SetWindowTextA(proc.MainWindowHandle, "Habbo Hotel");

            if (isShockwave)
            {
                SetWindowLong(proc.MainWindowHandle, -16, (int)(GetWindowLong(proc.MainWindowHandle, -16) & ~0x00040000L));
                SetWindowLong(proc.MainWindowHandle, -16, (int)(GetWindowLong(proc.MainWindowHandle, -16) & ~0x00010000L));
            }
        }

        private void GetTicket()
        {
            var httpClient = new HttpClient();

            var response = httpClient.GetAsync($"{_site}/api/ticket?username={username.Text}&password={password.Text}").Result;
        
            if (response.StatusCode != System.Net.HttpStatusCode.OK)
            {
                MessageBox.Show("Invalid username or password", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                
                password.Text = "";
                password.Focus();
                enterShockwave.Enabled = false;
                enterFlash.Enabled = false;

                File.WriteAllLines(_path + @"\config.txt", new string[] { username.Text, string.Empty });
            }
            else
            {
                _details = JsonSerializer.Deserialize<Details>(response.Content.ReadAsStringAsync().Result, new JsonSerializerOptions
                {
                    PropertyNameCaseInsensitive = true
                });

                if (rememberMe.Checked)
                {
                    File.WriteAllLines(_path + @"\config.txt", new string[] { username.Text, password.Text });
                }
            }
        }

        private void UsernamePasswordChanged(object? sender, EventArgs? e)
        {
            enterShockwave.Enabled = !string.IsNullOrEmpty(username.Text) && !string.IsNullOrEmpty(password.Text);
            enterFlash.Enabled = !string.IsNullOrEmpty(username.Text) && !string.IsNullOrEmpty(password.Text);
        }

        private void RememberMeChanged(object sender, EventArgs e)
        {
            if (!rememberMe.Checked)
            {
                File.WriteAllBytes(_path + @"\config.txt", new byte[] { });
            }
        }

        private void Form_Shown(object sender, EventArgs e)
        {
            UsernamePasswordChanged(null, null);

            if (!string.IsNullOrEmpty(username.Text) && string.IsNullOrEmpty(password.Text))
            {
                password.Focus();
            }

            if (!string.IsNullOrEmpty(username.Text) && !string.IsNullOrEmpty(password.Text))
            {
                enterShockwave.Focus();
            }
        }

        private void OpenWebsite(object sender, EventArgs e)
        {
            Process.Start(new ProcessStartInfo("https://YOUR-HOTEL-HERE/")
            {
                UseShellExecute = true
            });
        }

        private void DebugMode(object sender, EventArgs e)
        {
            _site = "http://localhost";
            MessageBox.Show("Will now connect to http://localhost", "Notice", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        [DllImport("user32.dll")]
        static extern bool SetWindowTextA(IntPtr hWnd, string text);

        [DllImport("user32.dll", EntryPoint = "GetWindowLong")]
        public static extern int GetWindowLong(IntPtr hWnd, int nIndex);

        [DllImport("user32.dll", EntryPoint = "SetWindowLong")]
        public static extern int SetWindowLong(IntPtr hWnd, int nIndex, int dwNewLong);

        private class Details
        {
            public string Host { get; set; }
            public string Site { get; set; }
            public string MusPort { get; set; }
            public string ShockwavePort { get; set; }
            public string ShockwaveDcr { get; set; }
            public string ShockwaveVariables { get; set; }
            public string ShockwaveTexts { get; set; }
            public string FlashPort { get; set; }
            public string FlashBase { get; set; }
            public string FlashSwf { get; set; }
            public string FlashVariables { get; set; }
            public string FlashTexts { get; set; }
            public string SsoTicket { get; set; }
        }
    }
}