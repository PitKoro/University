﻿using System;
using System.Windows.Forms;

namespace GraphDZ2
{
    static class Program
    {
        /// <summary>
        /// Главная точка входа для приложения.
        /// </summary>
        [STAThread]
        static void Main()
        {
            ResizableImage image = new ResizableImage("C:\\Users\\Petr\\Pictures\\123.jpg");
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1(image.getImage(2)));
        }
    }
}
