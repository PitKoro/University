using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace lab1
{
    public partial class questionnaireForm : Form
    {
        public questionnaireForm()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button_Click(object sender, EventArgs e)
        {
            resultForm result = new resultForm(this.textBoxFIO.Text, this.numericUpDownYearOfBirth.Value, this.radioButtonMale.Checked, this.checkBoxMarriage.Checked, this.comboBoxCity.Text);
            result.Show();
        }
    }
}
