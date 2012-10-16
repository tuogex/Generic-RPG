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
            this.noMusicCirc = new System.Windows.Forms.RadioButton();
            this.gameMusicCirc = new System.Windows.Forms.RadioButton();
            this.officialWeb = new System.Windows.Forms.LinkLabel();
            this.resetSaves = new System.Windows.Forms.CheckBox();
            this.firstTime = new System.Windows.Forms.CheckBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.xWinBox = new System.Windows.Forms.TextBox();
            this.yWinBox = new System.Windows.Forms.TextBox();
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
            this.SubmitButton.Location = new System.Drawing.Point(154, 203);
            this.SubmitButton.Name = "SubmitButton";
            this.SubmitButton.Size = new System.Drawing.Size(75, 23);
            this.SubmitButton.TabIndex = 4;
            this.SubmitButton.Text = "Play!";
            this.SubmitButton.UseVisualStyleBackColor = true;
            this.SubmitButton.Click += new System.EventHandler(this.button1_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(136, 9);
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
            this.groupBox1.Location = new System.Drawing.Point(258, 12);
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
            this.groupBox2.Controls.Add(this.gameMusicCirc);
            this.groupBox2.Location = new System.Drawing.Point(258, 107);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(128, 78);
            this.groupBox2.TabIndex = 8;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Audio Preference";
            this.groupBox2.Enter += new System.EventHandler(this.groupBox2_Enter);
            // 
            // noMusicCirc
            // 
            this.noMusicCirc.AutoSize = true;
            this.noMusicCirc.Location = new System.Drawing.Point(7, 43);
            this.noMusicCirc.Name = "noMusicCirc";
            this.noMusicCirc.Size = new System.Drawing.Size(70, 17);
            this.noMusicCirc.TabIndex = 2;
            this.noMusicCirc.TabStop = true;
            this.noMusicCirc.Text = "No Music";
            this.noMusicCirc.UseVisualStyleBackColor = true;
            this.noMusicCirc.CheckedChanged += new System.EventHandler(this.noMusicCirc_CheckedChanged);
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
            // officialWeb
            // 
            this.officialWeb.AutoSize = true;
            this.officialWeb.Location = new System.Drawing.Point(9, 213);
            this.officialWeb.Name = "officialWeb";
            this.officialWeb.Size = new System.Drawing.Size(121, 13);
            this.officialWeb.TabIndex = 9;
            this.officialWeb.TabStop = true;
            this.officialWeb.Text = "Visit the Official Website";
            this.officialWeb.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.officialWeb_LinkClicked);
            // 
            // resetSaves
            // 
            this.resetSaves.AutoSize = true;
            this.resetSaves.Location = new System.Drawing.Point(12, 105);
            this.resetSaves.Name = "resetSaves";
            this.resetSaves.Size = new System.Drawing.Size(93, 17);
            this.resetSaves.TabIndex = 10;
            this.resetSaves.Text = "Reset Saves?";
            this.resetSaves.UseVisualStyleBackColor = true;
            this.resetSaves.CheckedChanged += new System.EventHandler(this.resetSaves_CheckedChanged);
            // 
            // firstTime
            // 
            this.firstTime.AutoSize = true;
            this.firstTime.Location = new System.Drawing.Point(12, 12);
            this.firstTime.Name = "firstTime";
            this.firstTime.Size = new System.Drawing.Size(114, 17);
            this.firstTime.TabIndex = 11;
            this.firstTime.Text = "First Time Playing?";
            this.firstTime.UseVisualStyleBackColor = true;
            this.firstTime.CheckedChanged += new System.EventHandler(this.firstTime_CheckedChanged);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(68, 130);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(102, 13);
            this.label2.TabIndex = 14;
            this.label2.Text = "Game window width";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(68, 156);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(106, 13);
            this.label3.TabIndex = 15;
            this.label3.Text = "Game window height";
            // 
            // xWinBox
            // 
            this.xWinBox.Location = new System.Drawing.Point(12, 127);
            this.xWinBox.Name = "xWinBox";
            this.xWinBox.Size = new System.Drawing.Size(50, 20);
            this.xWinBox.TabIndex = 16;
            this.xWinBox.Text = "800";
            this.xWinBox.TextChanged += new System.EventHandler(this.xWinBox_TextChanged);
            // 
            // yWinBox
            // 
            this.yWinBox.Location = new System.Drawing.Point(12, 156);
            this.yWinBox.Name = "yWinBox";
            this.yWinBox.Size = new System.Drawing.Size(50, 20);
            this.yWinBox.TabIndex = 17;
            this.yWinBox.Text = "600";
            this.yWinBox.TextChanged += new System.EventHandler(this.yWinBox_TextChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(398, 238);
            this.Controls.Add(this.yWinBox);
            this.Controls.Add(this.xWinBox);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.firstTime);
            this.Controls.Add(this.resetSaves);
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
        private System.Windows.Forms.RadioButton noMusicCirc;
        private System.Windows.Forms.LinkLabel officialWeb;
        private System.Windows.Forms.CheckBox resetSaves;
        private System.Windows.Forms.CheckBox firstTime;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox xWinBox;
        private System.Windows.Forms.TextBox yWinBox;

    }
}

