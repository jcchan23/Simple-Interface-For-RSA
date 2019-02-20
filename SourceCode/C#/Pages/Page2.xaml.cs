using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
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

namespace Study
{
    /// <summary>
    /// Page2.xaml 的交互逻辑
    /// </summary>
    public partial class Page2 : Page
    {
        //三个供加密方法调用的全局变量
        public String Encryption_Text;
        public String Public_Key;
        public String BigInteger_n;

        [DllImport("RSA.dll")]
        public static extern IntPtr Cal(string text, string key, string integer);

        public Page2()
        {
            InitializeComponent();
        }

        private void TextFile_Select_Button_Click(object sender, RoutedEventArgs e)
        {
            Encryption_Text = FileOperation.UploadFiles(Encryption_Text);
            TextFile_Select_Label.Content = "Upload Succeed!";
        }

        private void EncryptionFile_Select_Button_Click(object sender, RoutedEventArgs e)
        {
            Public_Key = FileOperation.UploadFiles(Public_Key);
            EncryptionFile_Select_Label.Content = "Upload Succeed!";
        }

        private void BigInteger_Select_Button_Click(object sender, RoutedEventArgs e)
        {
            BigInteger_n = FileOperation.UploadFiles(BigInteger_n);
            BigInteger_Label.Content = "Upload Succeed!";
        }

        private void Encryption_Button_Click(object sender, RoutedEventArgs e)
        {
            string result = Encoding.UTF8.GetString(Encoding.Unicode.GetBytes(Marshal.PtrToStringAuto(Cal(Encryption_Text, Public_Key, BigInteger_n))));
            FileOperation.WriteFiles(result, "Cipher_Text.txt");
            MessageBox.Show("加密成功，请查看已生成的同目录下的Cipher_Text.txt");
        }

    }
}
