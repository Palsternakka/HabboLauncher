#include <Windows.h>
#include <cstdint>
#include <string>

namespace HabboLauncherCpp
{
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Reflection;
	using namespace System::Net::Http;

	public ref class Form : public System::Windows::Forms::Form
	{
		private: ref class Details
		{
			public: System::String^ Host;
			public: System::String^ Site;
			public: System::String^ MusPort;
			public: System::String^ ShockwavePort;
			public: System::String^ ShockwaveDcr;
			public: System::String^ ShockwaveVariables;
			public: System::String^ ShockwaveTexts;
			public: System::String^ FlashPort;
			public: System::String^ FlashBase;
			public: System::String^ FlashSwf;
			public: System::String^ FlashVariables;
			public: System::String^ FlashTexts;
			public: System::String^ SsoTicket;
		};

		private: System::String^ _path;
		private: System::String^ _site;
		private: Details^ _details;

		public: Form(void)
		{
			_path = System::Environment::ExpandEnvironmentVariables("%AppData%\\HabboLauncher");
			_site = gcnew System::String("https://YOUR-HOTEL-HERE");

			InitializeComponent();
		}

		protected: ~Form()
		{
			if (components)
			{
				delete components;
			}
		}

		private: System::Windows::Forms::Panel^ logo;
		private: System::Windows::Forms::TextBox^ username;
		private: System::Windows::Forms::TextBox^ password;
		private: System::Windows::Forms::Label^ usernameLabel;
		private: System::Windows::Forms::Label^ passwordLabel;
		private: System::Windows::Forms::Button^ enterFlash;
		private: System::Windows::Forms::Button^ enterShockwave;
		private: System::Windows::Forms::Button^ openWebsite;
		private: System::Windows::Forms::CheckBox^ rememberMe;
		private: System::ComponentModel::Container^ components;

		private: MemoryStream^ GetStreamFromResource(System::String^ name)
		{
			MemoryStream^ stream = gcnew MemoryStream();
			Assembly::GetExecutingAssembly()->GetManifestResourceStream(name)->CopyTo(stream);

			return stream;
		}

		void InitializeComponent(void)
		{
			this->logo = (gcnew System::Windows::Forms::Panel());
			this->username = (gcnew System::Windows::Forms::TextBox());
			this->password = (gcnew System::Windows::Forms::TextBox());
			this->usernameLabel = (gcnew System::Windows::Forms::Label());
			this->passwordLabel = (gcnew System::Windows::Forms::Label());
			this->enterFlash = (gcnew System::Windows::Forms::Button());
			this->enterShockwave = (gcnew System::Windows::Forms::Button());
			this->openWebsite = (gcnew System::Windows::Forms::Button());
			this->rememberMe = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// logo
			// 
			this->logo->Location = System::Drawing::Point(37, 12);
			this->logo->Name = L"logo";
			this->logo->Size = System::Drawing::Size(111, 42);
			this->logo->TabIndex = 0;
			this->logo->BackgroundImage = Image::FromStream(GetStreamFromResource("Logo.png"));
			this->logo->DoubleClick += gcnew System::EventHandler(this, &Form::DebugMode);

			// 
			// username
			// 
			this->username->Location = System::Drawing::Point(73, 67);
			this->username->Name = L"username";
			this->username->Size = System::Drawing::Size(100, 20);
			this->username->TabIndex = 2;
			this->username->TextChanged += gcnew System::EventHandler(this, &Form::UsernamePasswordChanged);
			// 
			// password
			// 
			this->password->Location = System::Drawing::Point(73, 94);
			this->password->Name = L"password";
			this->password->Size = System::Drawing::Size(100, 20);
			this->password->TabIndex = 4;
			this->password->UseSystemPasswordChar = true;
			this->password->TextChanged += gcnew System::EventHandler(this, &Form::UsernamePasswordChanged);
			// 
			// usernameLabel
			// 
			this->usernameLabel->AutoSize = true;
			this->usernameLabel->Location = System::Drawing::Point(12, 70);
			this->usernameLabel->Name = L"usernameLabel";
			this->usernameLabel->Size = System::Drawing::Size(55, 13);
			this->usernameLabel->TabIndex = 1;
			this->usernameLabel->Text = L"Username";
			// 
			// passwordLabel
			// 
			this->passwordLabel->AutoSize = true;
			this->passwordLabel->Location = System::Drawing::Point(12, 97);
			this->passwordLabel->Name = L"passwordLabel";
			this->passwordLabel->Size = System::Drawing::Size(53, 13);
			this->passwordLabel->TabIndex = 3;
			this->passwordLabel->Text = L"Password";
			// 
			// enterFlash
			// 
			this->enterFlash->Enabled = false;
			this->enterFlash->Location = System::Drawing::Point(12, 172);
			this->enterFlash->Name = L"enterFlash";
			this->enterFlash->Size = System::Drawing::Size(161, 23);
			this->enterFlash->TabIndex = 7;
			this->enterFlash->Text = L"Enter Flash";
			this->enterFlash->UseVisualStyleBackColor = true;
			this->enterFlash->Click += gcnew System::EventHandler(this, &Form::EnterFlash);
			// 
			// enterShockwave
			// 
			this->enterShockwave->Enabled = false;
			this->enterShockwave->Location = System::Drawing::Point(12, 143);
			this->enterShockwave->Name = L"enterShockwave";
			this->enterShockwave->Size = System::Drawing::Size(161, 23);
			this->enterShockwave->TabIndex = 6;
			this->enterShockwave->Text = L"Enter Shockwave";
			this->enterShockwave->UseVisualStyleBackColor = true;
			this->enterShockwave->Click += gcnew System::EventHandler(this, &Form::EnterShockwave);
			// 
			// openWebsite
			// 
			this->openWebsite->Location = System::Drawing::Point(12, 201);
			this->openWebsite->Name = L"openWebsite";
			this->openWebsite->Size = System::Drawing::Size(161, 23);
			this->openWebsite->TabIndex = 8;
			this->openWebsite->Text = L"Open Website";
			this->openWebsite->UseVisualStyleBackColor = true;
			this->openWebsite->Click += gcnew System::EventHandler(this, &Form::OpenWebsite);
			// 
			// rememberMe
			// 
			this->rememberMe->AutoSize = true;
			this->rememberMe->Location = System::Drawing::Point(73, 120);
			this->rememberMe->Name = L"rememberMe";
			this->rememberMe->Size = System::Drawing::Size(94, 17);
			this->rememberMe->TabIndex = 5;
			this->rememberMe->Text = L"Remember me";
			this->rememberMe->UseVisualStyleBackColor = true;
			this->rememberMe->CheckedChanged += gcnew System::EventHandler(this, &Form::RememberMeChanged);
			// 
			// Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(183, 236);
			this->Controls->Add(this->rememberMe);
			this->Controls->Add(this->openWebsite);
			this->Controls->Add(this->enterShockwave);
			this->Controls->Add(this->enterFlash);
			this->Controls->Add(this->passwordLabel);
			this->Controls->Add(this->usernameLabel);
			this->Controls->Add(this->password);
			this->Controls->Add(this->username);
			this->Controls->Add(this->logo);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Habbo Launcher";
			this->Load += gcnew System::EventHandler(this, &Form::Form_Load);
			this->Shown += gcnew System::EventHandler(this, &Form::Form_Shown);
			this->ResumeLayout(false);
			this->PerformLayout();

			MemoryStream^ s = GetStreamFromResource("Launcher.ico");
			s->Position = 0;

			this->Icon = gcnew System::Drawing::Icon(s);
		}

		private: void Form_Load(System::Object^ sender, System::EventArgs^ e)
		{
			try
			{
				array<System::String^>^ settings = File::ReadAllLines(_path + "\\config.txt");

				if (settings->Length == 2)
				{
					username->Text = settings[0];
					password->Text = settings[1];
					rememberMe->Checked = true;
				}
			}
			catch (DirectoryNotFoundException^)
			{
				Directory::CreateDirectory(_path);

				File::Create(_path + "\\config.txt");
			}
			catch (FileNotFoundException^)
			{
				File::Create(_path + "\\config.txt");
			}

			UnzipProjectors();
		}

		private: void UnzipProjectors()
		{
			DeleteDirectoryIfExists(_path + "\\Flash");
			DeleteDirectoryIfExists(_path + "\\Shockwave");

			File::WriteAllBytes(_path + "\\Projectors.zip", GetStreamFromResource("Projectors.bin")->ToArray());

			System::IO::Compression::ZipFile::ExtractToDirectory(_path + "\\Projectors.zip", _path);

			File::Delete(_path + "\\Projectors.zip");
		}

		private: void DeleteDirectoryIfExists(System::String^ path)
		{
			DirectoryInfo^ directory = gcnew DirectoryInfo(path);

			if (directory->Exists)
			{
				try
				{
					directory->Delete(true);
				}
				catch (System::Exception^ ex) { }
			}
		}

		private: void EnterShockwave(System::Object^ sender, System::EventArgs^ e)
		{
			Cursor = Cursors::WaitCursor;

			GetTicket();

			if (_details != nullptr)
			{
				array<System::String^>^ arr =  gcnew array<System::String^>(8);
				arr[0] = _details->Host;
				arr[1] = _details->ShockwavePort;
				arr[2] = _details->MusPort;
				arr[3] = _details->Site;
				arr[4] = _details->ShockwaveTexts;
				arr[5] = _details->ShockwaveVariables;
				arr[6] = _details->ShockwaveDcr;
				arr[7] = _details->SsoTicket;

				File::WriteAllLines(_path + "\\Shockwave\\vars.txt", arr);

				System::Diagnostics::Process^ proc = System::Diagnostics::Process::Start(gcnew System::Diagnostics::ProcessStartInfo(_path + "\\Shockwave\\Habbo Hotel.exe"));

				ChangeWindowTitle(proc, true);

				Application::Exit();
			}

			Cursor = Cursors::Arrow;
		}

		private: void EnterFlash(System::Object^ sender, System::EventArgs^ e)
		{
			Cursor = Cursors::WaitCursor;

			GetTicket();

			if (_details != nullptr)
			{
				System::Diagnostics::ProcessStartInfo^ psi = gcnew System::Diagnostics::ProcessStartInfo(_path + "\\Flash\\Habbo Hotel.exe");

				psi->Arguments = _details->FlashSwf + "?client.allow.cross.domain=1&client.notify.cross.domain=0&connection.info.host=" + _details->Host + "&connection.info.port=" + _details->FlashPort + "&site.url" + _details->Site + "/&url.prefix=" + _details->Site + "/&client.reload.url=/disconnected&client.fatal.error.url=" + _details->Site + "/disconnected&client.connection.failed.url=" + _details->Site + "/disconnected&external.variables.txt=" + _details->FlashVariables + "?&external.texts.txt=" + _details->FlashTexts + "?&use.sso.ticket=1&sso.ticket=" + _details->SsoTicket + "&processlog.enabled=1&account_id=1&client.starting=Please wait! Habbo is starting up&flash.client.url=" + _details->FlashBase + "&user.hash=ticket&has.identity=0&flash.client.origin=popup&country_code=US";

				System::Diagnostics::Process^ proc = System::Diagnostics::Process::Start(psi);

				ChangeWindowTitle(proc, false);

				Application::Exit();
			}

			Cursor = Cursors::Arrow;
		}

		private: void ChangeWindowTitle(System::Diagnostics::Process^ proc, System::Boolean isShockwave) 
		{
			while (static_cast<HWND>(proc->MainWindowHandle.ToPointer()) == 0)
			{
				Sleep(500);
			}

			HWND handle = static_cast<HWND>(proc->MainWindowHandle.ToPointer());

			SetWindowTextA(handle, "Habbo Hotel");

			if (isShockwave)
			{
				SetWindowLong(handle, -16, GetWindowLong(handle, -16) & ~0x00040000L);
				SetWindowLong(handle, -16, GetWindowLong(handle, -16) & ~0x00010000L);
			}
		}

		private: void GetTicket()
		{
			HttpClient^ httpClient = gcnew HttpClient();

			HttpResponseMessage^ response = httpClient->GetAsync(_site + "/api/ticket?username=" + username->Text + "&password=" + password->Text)->Result;

			if (response->StatusCode != System::Net::HttpStatusCode::OK)
			{
				MessageBox::Show("Invalid username or password", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);

				password->Text = "";
				password->Focus();
				enterShockwave->Enabled = false;
				enterFlash->Enabled = false;

				File::WriteAllText(_path + "\\config.txt", username->Text + "\r\n" + "");
			}
			else
			{
				// Had to write my own 'deserializer' because don't want DLL dependencies
				//_details = Newtonsoft::Json::JsonConvert::DeserializeObject<Details^>(response->Content->ReadAsStringAsync()->Result);
				_details = ParseJsonToDetails(response->Content->ReadAsStringAsync()->Result);

				if (rememberMe->Checked == true)
				{
					File::WriteAllText(_path + "\\config.txt", username->Text + "\r\n" + password->Text);
				}
			}
		}

		private: Details^ ParseJsonToDetails(System::String^ json)
		{
			json = json->Replace("{", "");
			json = json->Replace("}", "");
			json = json->Replace("\r", "");
			json = json->Replace("\n", "");
			array<System::String^>^ items = json->Split(',');
			array<System::String^>^ itemValues = gcnew array<System::String^>(13);

			System::Int32 i = 0;

			for each (System::String ^ item in items)
			{
				System::Int32 count = 0;
				System::Int32 index = 0;

				for (System::Int32 j = 0; j < item->Length; j++)
				{
					if (item[j] == '"')
					{
						count++;

						if (count == 3)
						{
							index = j;
							break;
						}
					}
				}

				itemValues[i] = item->Substring(index + 1)->TrimEnd('"');
				i++;
			}

			Details^ details = gcnew Details();
			details->Host = itemValues[0];
			details->Site = itemValues[1];
			details->MusPort = itemValues[2];
			details->ShockwavePort = itemValues[3];
			details->ShockwaveDcr = itemValues[4];
			details->ShockwaveVariables = itemValues[5];
			details->ShockwaveTexts = itemValues[6];
			details->FlashPort = itemValues[7];
			details->FlashBase = itemValues[8];
			details->FlashSwf = itemValues[9];
			details->FlashVariables = itemValues[10];
			details->FlashTexts = itemValues[11];
			details->SsoTicket = itemValues[12];

			return details;
		}

		private: void UsernamePasswordChanged(System::Object^ sender, System::EventArgs^ e)
		{
			if (username->Text != gcnew System::String("") && password->Text != gcnew System::String(""))
			{
				enterShockwave->Enabled = true;
				enterFlash->Enabled = true;
			}
			else
			{
				enterShockwave->Enabled = false;
				enterFlash->Enabled = false;
			}
		}

		private: void RememberMeChanged(System::Object^ sender, System::EventArgs^ e)
		{
			if (rememberMe->Checked == false)
			{
				File::WriteAllBytes(_path + "\\config.txt", gcnew array<System::Byte> { });
			}
		}

		private: void Form_Shown(System::Object^ sender, System::EventArgs^ e)
		{
			UsernamePasswordChanged(nullptr, nullptr);

			if (username->Text != gcnew System::String("") && password->Text == gcnew System::String(""))
			{
				password->Focus();
			}

			if (username->Text != gcnew System::String("") && password->Text != gcnew System::String(""))
			{
				enterShockwave->Focus();
			}
		}

		private: void OpenWebsite(System::Object^ sender, System::EventArgs^ e)
		{
			System::Diagnostics::ProcessStartInfo^ psi = gcnew System::Diagnostics::ProcessStartInfo("https://YOUR-HOTEL-HERE/");
			psi->UseShellExecute = true;

			System::Diagnostics::Process::Start(psi);
		}

		private: void DebugMode(System::Object^ sender, System::EventArgs^ e)
		{
			_site = gcnew System::String("http://localhost");
			MessageBox::Show("Will now connect to http://localhost", "Notice", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	};
}
