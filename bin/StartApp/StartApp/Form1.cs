﻿using System;
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
        TextWriter fg = new StreamWriter("bin/settings/graphics");
        TextWriter sg = new StreamWriter("bin/settings/saveGame");
        TextWriter mw = new StreamWriter("bin/settings/musicPref");
        TextWriter xw = new StreamWriter("bin/settings/zombAmt");
        TextWriter yw = new StreamWriter("bin/settings/skelAmt");
        TextWriter gn = new StreamWriter("bin/settings/ghostAmt");

        Process rpg = new Process();
        Process reset_saves = new Process();

        public Form1()
        {
            InitializeComponent();
            rpg.StartInfo.FileName = "start.shortcut.bat";
            reset_saves.StartInfo.FileName = "reset_saves.bat";
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
                dm.WriteLine("yes");
            }
            else
            {
                dm.WriteLine("no");
            }

            if (cal13cen.Checked)
            {
                tc.WriteLine("1");
            }
            else
            {
                tc.WriteLine("0");
            }

            if (fancyBox.Checked)
            {
                fg.WriteLine("high");
            }
            else
            {
                fg.WriteLine("low");
            }

            string gameSave = "0";

            if (radioButton1.Checked)
            {
                gameSave = "1";
            }
            else if (radioButton2.Checked)
            {
                gameSave = "2";
            }
            else if (radioButton3.Checked)
            {
                gameSave = "3";
            }


            string musicString = "0";

            if (gameMusicCirc.Checked)
            {
                musicString = "1";
            }
            else if (noMusicCirc.Checked)
            {
                musicString = "2";
            }

            if (resetSaves.Checked || firstTime.Checked)
            {
                reset_saves.Start();
            }
            sg.WriteLine(gameSave);
            mw.WriteLine(musicString);

            xw.WriteLine(zombNum.Text);
            yw.WriteLine(skelNum.Text);
            gn.WriteLine(ghostNum.Text);

            xw.Close();
            yw.Close();
            dm.Close();
            tc.Close();
            fg.Close();
            sg.Close();
            mw.Close();
            gn.Close();
            rpg.Start();
            Environment.Exit(0);

        }

        private void fancyBox_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void radioButton3_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void gameMusicCirc_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void userMusicCirc_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void noMusicCirc_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void officialWeb_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            string url = @"http://jacob-hegna.github.com/Generic-RPG/";
            System.Diagnostics.Process.Start(url);
        }

        private void resetSaves_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void firstTime_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void groupBox2_Enter(object sender, EventArgs e)
        {

        }

        private void xWinBox_TextChanged(object sender, EventArgs e)
        {

        }

        private void yWinBox_TextChanged(object sender, EventArgs e)
        {

        }

  
    }
}
