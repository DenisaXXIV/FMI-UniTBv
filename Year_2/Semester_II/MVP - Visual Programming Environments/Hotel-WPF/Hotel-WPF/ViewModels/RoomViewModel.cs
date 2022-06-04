using Hotel_WPF.DAL.Entities;
using Hotel_WPF.DAL.Interfaces;
using Hotel_WPF.DAL.Repositories;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace Hotel_WPF.ViewModels
{
    public class RoomViewModel : INotifyPropertyChanged
    {

        public Room Room { get; set; }
        public RoomType RoomType { get; set; }
        public RoomFacilities RoomFacilities { get; set; }
        public Facilities Facilities { get; set; }
        #region Events
        public event PropertyChangedEventHandler? PropertyChanged;
        //public event EventHandler OnRequestClose;

        protected void OnPropertyChanged([CallerMemberName] string name = null)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(name));
        }
        #endregion
    }
}
