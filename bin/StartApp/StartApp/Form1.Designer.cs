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
            this.devModeBox = new System.Windows.Forms.CheckBox();
            this.cal13cen = new System.Windows.Forms.CheckBox();
            this.SubmitButton = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
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
            this.SubmitButton.Location = new System.Drawing.Point(47, 101);
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
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(210, 141);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.SubmitButton);
            this.Controls.Add(this.cal13cen);
            this.Controls.Add(this.devModeBox);
            this.Name = "Form1";
            this.Text = "Generic RPG ";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.CheckBox devModeBox;
        private System.Windows.Forms.CheckBox cal13cen;
        private System.Windows.Forms.Button SubmitButton;
        private System.Windows.Forms.Label label1;

    }
}

