using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Study
{
    public static class FileOperation
    {
        public static void WriteFiles(string content, string name)
        {
            //如果存在同名文件，则先清空原来里面的内容
            if (File.Exists(AppDomain.CurrentDomain.BaseDirectory + name))
            {
                System.IO.File.WriteAllText(AppDomain.CurrentDomain.BaseDirectory + name, string.Empty);
            }
            //写入新的内容
            FileStream fs1 = new FileStream(AppDomain.CurrentDomain.BaseDirectory + name, FileMode.Create, FileAccess.ReadWrite);
            StreamWriter sw1 = new StreamWriter(fs1);
            sw1.WriteLine(content);
            sw1.Close();
            fs1.Close();
        }

        public static string UploadFiles(String text_name)
        {
            Microsoft.Win32.OpenFileDialog dialog = new Microsoft.Win32.OpenFileDialog
            {
                Filter = "文本文件|*.txt"
            };
            if (dialog.ShowDialog() == true)
            {
                try
                {
                    StreamReader sr = new StreamReader(dialog.OpenFile(), System.Text.Encoding.Default);
                    text_name = sr.ReadToEnd().Trim();
                    sr.Close();
                }
                catch (Exception)
                {
                    throw;
                }
            }
            return text_name;
        }

        public static string Convert_String(byte[] text)
        {
            StringBuilder sBuilder = new StringBuilder();
            for (int i = 0; i < text.Length; i++)
            {
                sBuilder.Append(text[i].ToString("D2"));
            }
            return sBuilder.ToString();
        }
    }
}
