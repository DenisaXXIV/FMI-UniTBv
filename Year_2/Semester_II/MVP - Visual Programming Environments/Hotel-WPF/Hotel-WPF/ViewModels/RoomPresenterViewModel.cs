using Hotel_WPF.DAL.Entities;
using Hotel_WPF.DAL.Migrations;
using Hotel_WPF.DAL.Repositories;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace Hotel_WPF.ViewModels
{
    public class RoomPresenterViewModel : INotifyPropertyChanged
    {
        private ObservableCollection<RoomViewModel> _rooms = new();
        private readonly HotelDbContext _context = new HotelDbContext();

        public ObservableCollection<RoomViewModel> Rooms
        {
            get { return _rooms; }
            set
            {
                if (value != null)
                {
                    _rooms = value;
                    OnPropertyChanged(nameof(Rooms));
                }
            }
        }

        public RoomPresenterViewModel()
        {
            Start();
        }

        public void Start()
        {
            HotelRepository<Room>? roomRepo = new HotelRepository<Room>(_context);
            HotelRepository<RoomType>? roomTypeRepo = new HotelRepository<RoomType>(_context);
            HotelRepository<RoomFacilities>? roomFacRepo = new HotelRepository<RoomFacilities>(_context);
            HotelRepository<Facilities>? facRepo = new HotelRepository<Facilities>(_context);
            var rooms = roomRepo.GetAll().Result;
            foreach (var room in rooms)
            {
                List<RoomType>? types = roomTypeRepo.GetAll().Result.Where(x => x.IdRoomType.Equals(room.IdType)).ToList();
                List<RoomFacilities>? rf = roomFacRepo.GetAll().Result.Where(x => x.IdRoom.Equals(room.IdRoom)).ToList();
                List<Facilities>? facs = facRepo.GetAll().Result.Where(x => (rf.Select(s => s.IdFacilities).Contains(x.IdFacilities))).ToList();
                var obj = new RoomViewModel
                {
                    Room = room,
                    Facilities = facs.FirstOrDefault(),
                    RoomType = types.FirstOrDefault()
                };
                Rooms.Add(obj);
            }
        }

        public void Update()
        {

        }



        #region property
        public event PropertyChangedEventHandler? PropertyChanged;
        protected void OnPropertyChanged([CallerMemberName] string name = null)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(name));
        }
        #endregion
    }
}
