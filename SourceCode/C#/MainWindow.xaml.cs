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

namespace Study
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        private Dictionary<string, Uri> allViews = new Dictionary<string, Uri>();
        public MainWindow()
        {
            InitializeComponent();
            allViews.Add("page1", new Uri("Pages/Page1.xaml", UriKind.Relative));
            allViews.Add("page2", new Uri("Pages/Page2.xaml", UriKind.Relative));
            allViews.Add("page3", new Uri("Pages/Page3.xaml", UriKind.Relative));
        }

        private void InitialButton_Click(object sender, RoutedEventArgs e)
        {
            Change_Pages.Navigate(allViews["page1"]);
        }

        private void Encryption_Click(object sender, RoutedEventArgs e)
        {
            Change_Pages.Navigate(allViews["page2"]);
        }

        private void Decryption_Click(object sender, RoutedEventArgs e)
        {
            Change_Pages.Navigate(allViews["page3"]);
        }
    }
}
