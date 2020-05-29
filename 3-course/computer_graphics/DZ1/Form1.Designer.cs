namespace lab1
{
    partial class questionnaireForm
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.button = new System.Windows.Forms.Button();
            this.labelFIO = new System.Windows.Forms.Label();
            this.textBoxFIO = new System.Windows.Forms.TextBox();
            this.laberYearOfBirth = new System.Windows.Forms.Label();
            this.numericUpDownYearOfBirth = new System.Windows.Forms.NumericUpDown();
            this.radioButtonMale = new System.Windows.Forms.RadioButton();
            this.radioButtonFemale = new System.Windows.Forms.RadioButton();
            this.checkBoxMarriage = new System.Windows.Forms.CheckBox();
            this.genders = new System.Windows.Forms.GroupBox();
            this.labelMarriage = new System.Windows.Forms.Label();
            this.comboBoxCity = new System.Windows.Forms.ComboBox();
            this.labelCity = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownYearOfBirth)).BeginInit();
            this.genders.SuspendLayout();
            this.SuspendLayout();
            // 
            // button
            // 
            this.button.Location = new System.Drawing.Point(90, 276);
            this.button.Name = "button";
            this.button.Size = new System.Drawing.Size(75, 23);
            this.button.TabIndex = 0;
            this.button.Text = "Готово";
            this.button.UseVisualStyleBackColor = true;
            this.button.Click += new System.EventHandler(this.button_Click);
            // 
            // labelFIO
            // 
            this.labelFIO.AutoSize = true;
            this.labelFIO.Location = new System.Drawing.Point(22, 30);
            this.labelFIO.Name = "labelFIO";
            this.labelFIO.Size = new System.Drawing.Size(34, 13);
            this.labelFIO.TabIndex = 1;
            this.labelFIO.Text = "ФИО";
            // 
            // textBoxFIO
            // 
            this.textBoxFIO.Location = new System.Drawing.Point(134, 27);
            this.textBoxFIO.Name = "textBoxFIO";
            this.textBoxFIO.Size = new System.Drawing.Size(100, 20);
            this.textBoxFIO.TabIndex = 2;
            // 
            // laberYearOfBirth
            // 
            this.laberYearOfBirth.AutoSize = true;
            this.laberYearOfBirth.Location = new System.Drawing.Point(22, 66);
            this.laberYearOfBirth.Name = "laberYearOfBirth";
            this.laberYearOfBirth.Size = new System.Drawing.Size(78, 13);
            this.laberYearOfBirth.TabIndex = 3;
            this.laberYearOfBirth.Text = "Год рождения";
            // 
            // numericUpDownYearOfBirth
            // 
            this.numericUpDownYearOfBirth.Location = new System.Drawing.Point(134, 64);
            this.numericUpDownYearOfBirth.Maximum = new decimal(new int[] {
            2020,
            0,
            0,
            0});
            this.numericUpDownYearOfBirth.Minimum = new decimal(new int[] {
            1950,
            0,
            0,
            0});
            this.numericUpDownYearOfBirth.Name = "numericUpDownYearOfBirth";
            this.numericUpDownYearOfBirth.Size = new System.Drawing.Size(100, 20);
            this.numericUpDownYearOfBirth.TabIndex = 5;
            this.numericUpDownYearOfBirth.Value = new decimal(new int[] {
            2000,
            0,
            0,
            0});
            // 
            // radioButtonMale
            // 
            this.radioButtonMale.AutoSize = true;
            this.radioButtonMale.Checked = true;
            this.radioButtonMale.Location = new System.Drawing.Point(13, 28);
            this.radioButtonMale.Name = "radioButtonMale";
            this.radioButtonMale.Size = new System.Drawing.Size(70, 17);
            this.radioButtonMale.TabIndex = 6;
            this.radioButtonMale.TabStop = true;
            this.radioButtonMale.Text = "мужской";
            this.radioButtonMale.UseVisualStyleBackColor = true;
            // 
            // radioButtonFemale
            // 
            this.radioButtonFemale.AutoSize = true;
            this.radioButtonFemale.Location = new System.Drawing.Point(109, 28);
            this.radioButtonFemale.Name = "radioButtonFemale";
            this.radioButtonFemale.Size = new System.Drawing.Size(69, 17);
            this.radioButtonFemale.TabIndex = 7;
            this.radioButtonFemale.TabStop = true;
            this.radioButtonFemale.Text = "женский";
            this.radioButtonFemale.UseVisualStyleBackColor = true;
            // 
            // checkBoxMarriage
            // 
            this.checkBoxMarriage.AutoSize = true;
            this.checkBoxMarriage.Location = new System.Drawing.Point(25, 180);
            this.checkBoxMarriage.Name = "checkBoxMarriage";
            this.checkBoxMarriage.Size = new System.Drawing.Size(26, 17);
            this.checkBoxMarriage.TabIndex = 8;
            this.checkBoxMarriage.Text = "\r\n";
            this.checkBoxMarriage.UseVisualStyleBackColor = true;
            // 
            // genders
            // 
            this.genders.Controls.Add(this.radioButtonMale);
            this.genders.Controls.Add(this.radioButtonFemale);
            this.genders.Location = new System.Drawing.Point(25, 104);
            this.genders.Name = "genders";
            this.genders.Size = new System.Drawing.Size(200, 55);
            this.genders.TabIndex = 9;
            this.genders.TabStop = false;
            this.genders.Text = "Пол";
            // 
            // labelMarriage
            // 
            this.labelMarriage.AutoSize = true;
            this.labelMarriage.Location = new System.Drawing.Point(46, 181);
            this.labelMarriage.Name = "labelMarriage";
            this.labelMarriage.Size = new System.Drawing.Size(100, 13);
            this.labelMarriage.TabIndex = 10;
            this.labelMarriage.Text = "Женат / Замужем";
            // 
            // comboBoxCity
            // 
            this.comboBoxCity.FormattingEnabled = true;
            this.comboBoxCity.Items.AddRange(new object[] {
            "Москва",
            "Харьков",
            "посёлок Чушка",
            "с. Верхненовокутлумбетьево",
            "с. Муки-Какси"});
            this.comboBoxCity.Location = new System.Drawing.Point(90, 229);
            this.comboBoxCity.Name = "comboBoxCity";
            this.comboBoxCity.Size = new System.Drawing.Size(165, 21);
            this.comboBoxCity.TabIndex = 11;
            this.comboBoxCity.Text = "Москва";
            // 
            // labelCity
            // 
            this.labelCity.AutoSize = true;
            this.labelCity.Location = new System.Drawing.Point(22, 232);
            this.labelCity.Name = "labelCity";
            this.labelCity.Size = new System.Drawing.Size(37, 13);
            this.labelCity.TabIndex = 12;
            this.labelCity.Text = "Город";
            // 
            // questionnaireForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(267, 311);
            this.Controls.Add(this.labelCity);
            this.Controls.Add(this.comboBoxCity);
            this.Controls.Add(this.labelMarriage);
            this.Controls.Add(this.genders);
            this.Controls.Add(this.checkBoxMarriage);
            this.Controls.Add(this.numericUpDownYearOfBirth);
            this.Controls.Add(this.laberYearOfBirth);
            this.Controls.Add(this.textBoxFIO);
            this.Controls.Add(this.labelFIO);
            this.Controls.Add(this.button);
            this.Name = "questionnaireForm";
            this.Text = "Анкета";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownYearOfBirth)).EndInit();
            this.genders.ResumeLayout(false);
            this.genders.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button button;
        private System.Windows.Forms.Label labelFIO;
        private System.Windows.Forms.TextBox textBoxFIO;
        private System.Windows.Forms.Label laberYearOfBirth;
        private System.Windows.Forms.NumericUpDown numericUpDownYearOfBirth;
        private System.Windows.Forms.RadioButton radioButtonMale;
        private System.Windows.Forms.RadioButton radioButtonFemale;
        private System.Windows.Forms.CheckBox checkBoxMarriage;
        private System.Windows.Forms.GroupBox genders;
        private System.Windows.Forms.Label labelMarriage;
        private System.Windows.Forms.ComboBox comboBoxCity;
        private System.Windows.Forms.Label labelCity;
    }
}

