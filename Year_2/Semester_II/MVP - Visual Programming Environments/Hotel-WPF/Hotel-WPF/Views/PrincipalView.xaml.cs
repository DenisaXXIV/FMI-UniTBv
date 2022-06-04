using Hotel_WPF.DAL.Migrations;
using Hotel_WPF.ViewModels;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace Hotel_WPF.Views
{
    /// <summary>
    /// Interaction logic for PrincipalView.xaml
    /// </summary>
    public partial class PrincipalView : Window
    {

        public PrincipalView()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            LogIn l = new LogIn();
            l.Show();
        }
    }
}
