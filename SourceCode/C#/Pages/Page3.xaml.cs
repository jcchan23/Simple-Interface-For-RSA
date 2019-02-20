using System;
using System.Collections.Generic;
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
    /// Page3.xaml 的交互逻辑
    /// </summary>
    public partial class Page3 : Page
    {
        public String Decryption_Text;
        public String Private_Key;
        public String BigInteger_n;

        [DllImport("RSA.dll")]
        public static extern IntPtr Cal(string text, string key, string integer);

        public Page3()
        {
            InitializeComponent();
        }

        private void TextFile_Select_Button_Click(object sender, RoutedEventArgs e)
        {
            Decryption_Text = FileOperation.UploadFiles(Decryption_Text);
            TextFile_Select_Label.Content = "Upload Succeed!";
        }

        private void DecryptionFile_Select_Button_Click(object sender, RoutedEventArgs e)
        {
            Private_Key = FileOperation.UploadFiles(Private_Key);
            DecryptionFile_Select_Label.Content = "Upload Succeed!";
        }

        private void BigInteger_Select_Button_Click(object sender, RoutedEventArgs e)
        {
            BigInteger_n = FileOperation.UploadFiles(BigInteger_n);
            BigInteger_Label.Content = "Upload Succeed!";
        }

        private void Decryption_Button_Click(object sender, RoutedEventArgs e)
        {
            string result = Encoding.UTF8.GetString(Encoding.Unicode.GetBytes(Marshal.PtrToStringAuto(Cal(Decryption_Text, Private_Key, BigInteger_n))));
            FileOperation.WriteFiles(result, "Plain_Text.txt");
            MessageBox.Show("解密成功，请查看已生成的同目录下的Plain_Text.txt");
        }
    }
}
