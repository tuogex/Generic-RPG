using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Diagnostics;

namespace StartApp
{
    public partial class Form1 : Form
    {
        TextWriter dm = new StreamWriter("bin/settings/development-mode");
        TextWriter tc = new StreamWriter("bin/settings/13centurycalamity");

        public Form1()
        {
            InitializeComponent();
        }

        private void devModeBox_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void cal13cen_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (devModeBox.Checked)
            {
                dm.WriteLine("1");
            }
            else
            {
                dm.WriteLine("0");
            }

            if (cal13cen.Checked)
            {
                tc.WriteLine("1");
            }
            else
            {
                tc.WriteLine("0");
            }
            dm.Close();
            tc.Close();
            Process.Start("RPG.exe");
            Environment.Exit(0);

        }
    }
}
