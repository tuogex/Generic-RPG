namespace StartApp
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.devModeBox = new System.Windows.Forms.CheckBox();
            this.cal13cen = new System.Windows.Forms.CheckBox();
            this.SubmitButton = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.fancyBox = new System.Windows.Forms.CheckBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.radioButton3 = new System.Windows.Forms.RadioButton();
            this.radioButton2 = new System.Windows.Forms.RadioButton();
            this.radioButton1 = new System.Windows.Forms.RadioButton();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.gameMusicCirc = new System.Windows.Forms.RadioButton();
            this.userMusicCirc = new System.Windows.Forms.RadioButton();
            this.noMusicCirc = new System.Windows.Forms.RadioButton();
            this.officialWeb = new System.Windows.Forms.LinkLabel();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // devModeBox
            // 
            this.devModeBox.AccessibleName = "devModeBox";
            this.devModeBox.AutoSize = true;
            this.devModeBox.Location = new System.Drawing.Point(12, 36);
            this.devModeBox.Name = "devModeBox";
            this.devModeBox.Size = new System.Drawing.Size(110, 17);
            this.devModeBox.TabIndex = 0;
            this.devModeBox.Text = "Developer mode?";
            this.devModeBox.UseVisualStyleBackColor = true;
            this.devModeBox.CheckedChanged += new System.EventHandler(this.devModeBox_CheckedChanged);
            // 
            // cal13cen
            // 
            this.cal13cen.AutoSize = true;
            this.cal13cen.Location = new System.Drawing.Point(12, 59);
            this.cal13cen.Name = "cal13cen";
            this.cal13cen.Size = new System.Drawing.Size(177, 17);
            this.cal13cen.TabIndex = 3;
            this.cal13cen.Text = "Was the 13 Century a Calamity?";
            this.cal13cen.UseVisualStyleBackColor = true;
            this.cal13cen.CheckedChanged += new System.EventHandler(this.cal13cen_CheckedChanged);
            // 
            // SubmitButton
            // 
            this.SubmitButton.Location = new System.Drawing.Point(32, 168);
            this.SubmitButton.Name = "SubmitButton";
            this.SubmitButton.Size = new System.Drawing.Size(75, 23);
            this.SubmitButton.TabIndex = 4;
            this.SubmitButton.Text = "Submit";
            this.SubmitButton.UseVisualStyleBackColor = true;
            this.SubmitButton.Click += new System.EventHandler(this.button1_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(29, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(93, 13);
            this.label1.TabIndex = 5;
            this.label1.Text = "Pre-game Settings";
            // 
            // fancyBox
            // 
            this.fancyBox.AutoSize = true;
            this.fancyBox.Checked = true;
            this.fancyBox.CheckState = System.Windows.Forms.CheckState.Checked;
            this.fancyBox.Location = new System.Drawing.Point(12, 82);
            this.fancyBox.Name = "fancyBox";
            this.fancyBox.Size = new System.Drawing.Size(104, 17);
            this.fancyBox.TabIndex = 6;
            this.fancyBox.Text = "Fancy graphics?";
            this.fancyBox.UseVisualStyleBackColor = true;
            this.fancyBox.CheckedChanged += new System.EventHandler(this.fancyBox_CheckedChanged);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.radioButton3);
            this.groupBox1.Controls.Add(this.radioButton2);
            this.groupBox1.Controls.Add(this.radioButton1);
            this.groupBox1.Location = new System.Drawing.Point(221, 9);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(128, 89);
            this.groupBox1.TabIndex = 7;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Save";
            this.groupBox1.Enter += new System.EventHandler(this.groupBox1_Enter);
            // 
            // radioButton3
            // 
            this.radioButton3.AutoSize = true;
            this.radioButton3.Location = new System.Drawing.Point(7, 66);
            this.radioButton3.Name = "radioButton3";
            this.radioButton3.Size = new System.Drawing.Size(84, 17);
            this.radioButton3.TabIndex = 2;
            this.radioButton3.Text = "Game Three";
            this.radioButton3.UseVisualStyleBackColor = true;
            this.radioButton3.CheckedChanged += new System.EventHandler(this.radioButton3_CheckedChanged);
            // 
            // radioButton2
            // 
            this.radioButton2.AutoSize = true;
            this.radioButton2.Location = new System.Drawing.Point(7, 43);
            this.radioButton2.Name = "radioButton2";
            this.radioButton2.Size = new System.Drawing.Size(77, 17);
            this.radioButton2.TabIndex = 1;
            this.radioButton2.Text = "Game Two";
            this.radioButton2.UseVisualStyleBackColor = true;
            this.radioButton2.CheckedChanged += new System.EventHandler(this.radioButton2_CheckedChanged);
            // 
            // radioButton1
            // 
            this.radioButton1.AutoSize = true;
            this.radioButton1.Checked = true;
            this.radioButton1.Location = new System.Drawing.Point(7, 20);
            this.radioButton1.Name = "radioButton1";
            this.radioButton1.Size = new System.Drawing.Size(76, 17);
            this.radioButton1.TabIndex = 0;
            this.radioButton1.TabStop = true;
            this.radioButton1.Text = "Game One";
            this.radioButton1.UseVisualStyleBackColor = true;
            this.radioButton1.CheckedChanged += new System.EventHandler(this.radioButton1_CheckedChanged);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.noMusicCirc);
            this.groupBox2.Controls.Add(this.userMusicCirc);
            this.groupBox2.Controls.Add(this.gameMusicCirc);
            this.groupBox2.Location = new System.Drawing.Point(221, 105);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(128, 86);
            this.groupBox2.TabIndex = 8;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Audio Preference";
            // 
            // gameMusicCirc
            // 
            this.gameMusicCirc.AutoSize = true;
            this.gameMusicCirc.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.gameMusicCirc.Checked = true;
            this.gameMusicCirc.Location = new System.Drawing.Point(7, 20);
            this.gameMusicCirc.Name = "gameMusicCirc";
            this.gameMusicCirc.Size = new System.Drawing.Size(84, 17);
            this.gameMusicCirc.TabIndex = 0;
            this.gameMusicCirc.TabStop = true;
            this.gameMusicCirc.Text = "Game Music";
            this.gameMusicCirc.UseVisualStyleBackColor = true;
            this.gameMusicCirc.CheckedChanged += new System.EventHandler(this.gameMusicCirc_CheckedChanged);
            // 
            // userMusicCirc
            // 
            this.userMusicCirc.AutoSize = true;
            this.userMusicCirc.Location = new System.Drawing.Point(7, 43);
            this.userMusicCirc.Name = "userMusicCirc";
            this.userMusicCirc.Size = new System.Drawing.Size(78, 17);
            this.userMusicCirc.TabIndex = 1;
            this.userMusicCirc.TabStop = true;
            this.userMusicCirc.Text = "User Music";
            this.userMusicCirc.UseVisualStyleBackColor = true;
            this.userMusicCirc.CheckedChanged += new System.EventHandler(this.userMusicCirc_CheckedChanged);
            // 
            // noMusicCirc
            // 
            this.noMusicCirc.AutoSize = true;
            this.noMusicCirc.Location = new System.Drawing.Point(7, 66);
            this.noMusicCirc.Name = "noMusicCirc";
            this.noMusicCirc.Size = new System.Drawing.Size(70, 17);
            this.noMusicCirc.TabIndex = 2;
            this.noMusicCirc.TabStop = true;
            this.noMusicCirc.Text = "No Music";
            this.noMusicCirc.UseVisualStyleBackColor = true;
            this.noMusicCirc.CheckedChanged += new System.EventHandler(this.noMusicCirc_CheckedChanged);
            // 
            // officialWeb
            // 
            this.officialWeb.AutoSize = true;
            this.officialWeb.Location = new System.Drawing.Point(12, 125);
            this.officialWeb.Name = "officialWeb";
            this.officialWeb.Size = new System.Drawing.Size(121, 13);
            this.officialWeb.TabIndex = 9;
            this.officialWeb.TabStop = true;
            this.officialWeb.Text = "Visit the Official Website";
            this.officialWeb.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.officialWeb_LinkClicked);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(376, 203);
            this.Controls.Add(this.officialWeb);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.fancyBox);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.SubmitButton);
            this.Controls.Add(this.cal13cen);
            this.Controls.Add(this.devModeBox);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Form1";
            this.ShowInTaskbar = false;
            this.Text = "Generic RPG Launcher";
            this.TopMost = true;
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.CheckBox devModeBox;
        private System.Windows.Forms.CheckBox cal13cen;
        private System.Windows.Forms.Button SubmitButton;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.CheckBox fancyBox;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.RadioButton radioButton3;
        private System.Windows.Forms.RadioButton radioButton2;
        private System.Windows.Forms.RadioButton radioButton1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.RadioButton gameMusicCirc;
        private System.Windows.Forms.RadioButton userMusicCirc;
        private System.Windows.Forms.RadioButton noMusicCirc;
        private System.Windows.Forms.LinkLabel officialWeb;

    }
}

