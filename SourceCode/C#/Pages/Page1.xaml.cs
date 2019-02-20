using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.IO;
using System.Runtime.InteropServices;

namespace Study
{
    /// <summary>
    /// Page1.xaml 的交互逻辑
    /// </summary>
    public partial class Page1 : Page
    {
        [DllImport("RSA.dll")]
        public static extern void InitialNumbers(int InputBits);
        [DllImport("RSA.dll")]
        public static extern IntPtr GetBigInteger_n();
        [DllImport("RSA.dll")]
        public static extern IntPtr GetEncryption_Index();
        [DllImport("RSA.dll")]
        public static extern IntPtr GetDecryption_Index();

        public Page1()
        {
            InitializeComponent();
        }

        private void Initial_button_Click(object sender, RoutedEventArgs e)
        {
            //获取文本框的输入值
            var getInput = Initial_textbox.Text;
            if (string.IsNullOrEmpty(getInput.Trim()))
            {
                MessageBox.Show("输入不能为空，请重新输入！");
                Initial_textbox.Focus();
                return;
            }
            else
            {
                //输入值转换为数字
                int number = Convert.ToInt32(getInput);
                InitialNumbers(number);

                //调用C++的dll生成三个数字，大整数n，公钥d，私钥e
                string Big_Integer = Encoding.UTF8.GetString(Encoding.Unicode.GetBytes(Marshal.PtrToStringAuto(GetBigInteger_n())));
                string Public_Key = Encoding.UTF8.GetString(Encoding.Unicode.GetBytes(Marshal.PtrToStringAuto(GetEncryption_Index())));
                string Private_Key = Encoding.UTF8.GetString(Encoding.Unicode.GetBytes(Marshal.PtrToStringAuto(GetDecryption_Index())));

                //写入这三个值
                FileOperation.WriteFiles(Big_Integer, "Big_Integer.txt");
                FileOperation.WriteFiles(Public_Key, "Public_Key.txt");
                FileOperation.WriteFiles(Private_Key, "Private_Key.txt");
                MessageBox.Show("初始化成功，请查看已生成的同目录下的3个文件！");
            }
        }
    }
}
