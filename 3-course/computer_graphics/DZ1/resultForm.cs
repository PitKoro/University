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
    public partial class resultForm : Form
    {
        public resultForm(string fio, decimal yearOfBirth, bool gender, bool isMarriage, string city)
        {
            InitializeComponent();
            this.labelResultFIO.Text += " " + fio;
            this.labelResultYearOfBirth.Text += " " + yearOfBirth;
            if(gender)
                this.labelResultGender.Text += " Мужчина";
            else
                this.labelResultGender.Text += " Женщина";
            this.labelResultMarriage.Text += " " + isMarriage;
            this.labelResultCity.Text += " " + city;
        }
    }
}
