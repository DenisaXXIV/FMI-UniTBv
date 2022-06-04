using Hotel_WPF.DAL.Migrations;
using Hotel_WPF.ViewModels;
using Hotel_WPF.Views;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.DependencyInjection;
using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Threading.Tasks;
using System.Windows;
using Unity;

namespace Hotel_WPF
{
    /// <summary>
    /// Interaction logic for App.xaml
    /// </summary>
    public partial class App : Application
    {
        //private ServiceProvider serviceProvider;

        //public App()
        //{
        //    ServiceCollection services = new ServiceCollection();
        //    serviceProvider = services.BuildServiceProvider();
        //}



        //private void OnStartup(object sender, StartupEventArgs e)
        //{
        //    IUnityContainer container = new UnityContainer();
        //    container.RegisterType<HotelDbContext>();
        //    container.RegisterType<RoomPresenterViewModel>();
        //    container.RegisterType<PrincipalView>();

        //    var mainWindow = container.Resolve<PrincipalView>();
        //    mainWindow.Show();
        //}
    }
}
