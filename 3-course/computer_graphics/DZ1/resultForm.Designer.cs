namespace lab1
{
    partial class resultForm
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
            this.labelResultFIO = new System.Windows.Forms.Label();
            this.labelResultYearOfBirth = new System.Windows.Forms.Label();
            this.labelResultGender = new System.Windows.Forms.Label();
            this.labelResultMarriage = new System.Windows.Forms.Label();
            this.labelResultCity = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // labelResultFIO
            // 
            this.labelResultFIO.AutoSize = true;
            this.labelResultFIO.Location = new System.Drawing.Point(12, 9);
            this.labelResultFIO.Name = "labelResultFIO";
            this.labelResultFIO.Size = new System.Drawing.Size(37, 13);
            this.labelResultFIO.TabIndex = 2;
            this.labelResultFIO.Text = "ФИО:";
            // 
            // labelResultYearOfBirth
            // 
            this.labelResultYearOfBirth.AutoSize = true;
            this.labelResultYearOfBirth.Location = new System.Drawing.Point(12, 31);
            this.labelResultYearOfBirth.Name = "labelResultYearOfBirth";
            this.labelResultYearOfBirth.Size = new System.Drawing.Size(81, 13);
            this.labelResultYearOfBirth.TabIndex = 4;
            this.labelResultYearOfBirth.Text = "Год рождения:";
            // 
            // labelResultGender
            // 
            this.labelResultGender.AutoSize = true;
            this.labelResultGender.Location = new System.Drawing.Point(12, 53);
            this.labelResultGender.Name = "labelResultGender";
            this.labelResultGender.Size = new System.Drawing.Size(30, 13);
            this.labelResultGender.TabIndex = 5;
            this.labelResultGender.Text = "Пол:";
            // 
            // labelResultMarriage
            // 
            this.labelResultMarriage.AutoSize = true;
            this.labelResultMarriage.Location = new System.Drawing.Point(12, 75);
            this.labelResultMarriage.Name = "labelResultMarriage";
            this.labelResultMarriage.Size = new System.Drawing.Size(103, 13);
            this.labelResultMarriage.TabIndex = 11;
            this.labelResultMarriage.Text = "Женат / Замужем:";
            // 
            // labelResultCity
            // 
            this.labelResultCity.AutoSize = true;
            this.labelResultCity.Location = new System.Drawing.Point(12, 97);
            this.labelResultCity.Name = "labelResultCity";
            this.labelResultCity.Size = new System.Drawing.Size(40, 13);
            this.labelResultCity.TabIndex = 13;
            this.labelResultCity.Text = "Город:";
            // 
            // resultForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(318, 128);
            this.Controls.Add(this.labelResultCity);
            this.Controls.Add(this.labelResultMarriage);
            this.Controls.Add(this.labelResultGender);
            this.Controls.Add(this.labelResultYearOfBirth);
            this.Controls.Add(this.labelResultFIO);
            this.Name = "resultForm";
            this.Text = "Анкета";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label labelResultFIO;
        private System.Windows.Forms.Label labelResultYearOfBirth;
        private System.Windows.Forms.Label labelResultGender;
        private System.Windows.Forms.Label labelResultMarriage;
        private System.Windows.Forms.Label labelResultCity;
    }
}