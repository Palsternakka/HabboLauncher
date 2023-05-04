namespace HabboLauncher.Net
{
    partial class Form
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form));
            this.username = new System.Windows.Forms.TextBox();
            this.password = new System.Windows.Forms.TextBox();
            this.usernameLabel = new System.Windows.Forms.Label();
            this.passwordLabel = new System.Windows.Forms.Label();
            this.rememberMe = new System.Windows.Forms.CheckBox();
            this.enterFlash = new System.Windows.Forms.Button();
            this.enterShockwave = new System.Windows.Forms.Button();
            this.openWebsite = new System.Windows.Forms.Button();
            this.logo = new System.Windows.Forms.Panel();
            this.SuspendLayout();
            // 
            // username
            // 
            this.username.Location = new System.Drawing.Point(73, 67);
            this.username.Name = "username";
            this.username.Size = new System.Drawing.Size(100, 21);
            this.username.TabIndex = 2;
            this.username.TextChanged += new System.EventHandler(this.UsernamePasswordChanged);
            // 
            // password
            // 
            this.password.Location = new System.Drawing.Point(73, 94);
            this.password.Name = "password";
            this.password.Size = new System.Drawing.Size(100, 21);
            this.password.TabIndex = 4;
            this.password.UseSystemPasswordChar = true;
            this.password.TextChanged += new System.EventHandler(this.UsernamePasswordChanged);
            // 
            // usernameLabel
            // 
            this.usernameLabel.AutoSize = true;
            this.usernameLabel.Location = new System.Drawing.Point(12, 70);
            this.usernameLabel.Name = "usernameLabel";
            this.usernameLabel.Size = new System.Drawing.Size(55, 13);
            this.usernameLabel.TabIndex = 1;
            this.usernameLabel.Text = "Username";
            // 
            // passwordLabel
            // 
            this.passwordLabel.AutoSize = true;
            this.passwordLabel.Location = new System.Drawing.Point(12, 97);
            this.passwordLabel.Name = "passwordLabel";
            this.passwordLabel.Size = new System.Drawing.Size(53, 13);
            this.passwordLabel.TabIndex = 3;
            this.passwordLabel.Text = "Password";
            // 
            // rememberMe
            // 
            this.rememberMe.AutoSize = true;
            this.rememberMe.Location = new System.Drawing.Point(73, 121);
            this.rememberMe.Name = "rememberMe";
            this.rememberMe.Size = new System.Drawing.Size(94, 17);
            this.rememberMe.TabIndex = 5;
            this.rememberMe.Text = "Remember me";
            this.rememberMe.UseVisualStyleBackColor = true;
            this.rememberMe.CheckedChanged += new System.EventHandler(this.RememberMeChanged);
            // 
            // enterFlash
            // 
            this.enterFlash.Enabled = false;
            this.enterFlash.Location = new System.Drawing.Point(12, 173);
            this.enterFlash.Name = "enterFlash";
            this.enterFlash.Size = new System.Drawing.Size(161, 23);
            this.enterFlash.TabIndex = 7;
            this.enterFlash.Text = "Enter Flash";
            this.enterFlash.UseVisualStyleBackColor = true;
            this.enterFlash.Click += new System.EventHandler(this.EnterFlash);
            // 
            // enterShockwave
            // 
            this.enterShockwave.Enabled = false;
            this.enterShockwave.Location = new System.Drawing.Point(12, 144);
            this.enterShockwave.Name = "enterShockwave";
            this.enterShockwave.Size = new System.Drawing.Size(161, 23);
            this.enterShockwave.TabIndex = 6;
            this.enterShockwave.Text = "Enter Shockwave";
            this.enterShockwave.UseVisualStyleBackColor = true;
            this.enterShockwave.Click += new System.EventHandler(this.EnterShockwave);
            // 
            // openWebsite
            // 
            this.openWebsite.Location = new System.Drawing.Point(12, 202);
            this.openWebsite.Name = "openWebsite";
            this.openWebsite.Size = new System.Drawing.Size(161, 23);
            this.openWebsite.TabIndex = 8;
            this.openWebsite.Text = "Open Website";
            this.openWebsite.UseVisualStyleBackColor = true;
            this.openWebsite.Click += new System.EventHandler(this.OpenWebsite);
            // 
            // logo
            // 
            this.logo.Location = new System.Drawing.Point(37, 12);
            this.logo.Name = "logo";
            this.logo.Size = new System.Drawing.Size(111, 42);
            this.logo.TabIndex = 0;
            this.logo.BackgroundImage = Resources.Logo;
            this.logo.DoubleClick += new System.EventHandler(this.DebugMode);
            // 
            // Form
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(185, 238);
            this.Controls.Add(this.logo);
            this.Controls.Add(this.openWebsite);
            this.Controls.Add(this.enterShockwave);
            this.Controls.Add(this.enterFlash);
            this.Controls.Add(this.rememberMe);
            this.Controls.Add(this.passwordLabel);
            this.Controls.Add(this.usernameLabel);
            this.Controls.Add(this.password);
            this.Controls.Add(this.username);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Form";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Habbo Launcher";
            this.Load += new System.EventHandler(this.Form_Load);
            this.Shown += new System.EventHandler(this.Form_Shown);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private TextBox username;
        private TextBox password;
        private Label usernameLabel;
        private Label passwordLabel;
        private CheckBox rememberMe;
        private Button enterFlash;
        private Button enterShockwave;
        private Button openWebsite;
        private Panel logo;
    }
}