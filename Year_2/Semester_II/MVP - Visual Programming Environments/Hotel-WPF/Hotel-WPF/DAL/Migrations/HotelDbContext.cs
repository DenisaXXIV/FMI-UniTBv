using Hotel_WPF.DAL.Entities;
using Microsoft.EntityFrameworkCore;
using System;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hotel_WPF.DAL.Migrations
{
    public class HotelDbContext : DbContext
    {

        public DbSet<Facilities> Facilities { get; set; }
        public DbSet<Image> Images { get; set; }
        public DbSet<Offer> Offers { get; set; }
        public DbSet<Price> Prices { get; set; }
        public DbSet<Reservation> Reservations { get; set; }
        public DbSet<ReservationService> ReservationServices { get; set; }
        public DbSet<Role> Roles { get; set; }
        public DbSet<Room> Rooms { get; set; }
        public DbSet<RoomFacilities> RoomFacilities { get; set; }
        public DbSet<RoomReservation> RoomReservations { get; set; }
        public DbSet<RoomType> RoomTypes { get; set; }
        public DbSet<Service> Services { get; set; }
        public DbSet<User> Users { get; set; }

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            optionsBuilder.UseSqlServer(@"Server = (localdb)\mssqllocaldb; Database = HotelDatabase; 
                                        Integrated Security = True");
            optionsBuilder.UseLazyLoadingProxies();
        }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            base.OnModelCreating(modelBuilder);

            modelBuilder.Entity<Role>().HasData(
                new Role
                {
                    IdRole = 1,
                    Name = "Admin",
                },
                new Role
                {
                    IdRole = 2,
                    Name = "Client",
                },
                new Role
                {
                    IdRole = 3,
                    Name = "Employee",
                },
                new Role
                {
                    IdRole = 4,
                    Name = "Unauthorized User",
                });

            modelBuilder.Entity<RoomType>().HasData(
                new RoomType
                {
                    IdRoomType = 1,
                    Name = "1 bed"
                },
                new RoomType
                {
                    IdRoomType = 2,
                    Name = "2 beds"

                },
                new RoomType
                {
                    IdRoomType = 3,
                    Name = "3 beds"
                },
                new RoomType
                {
                    IdRoomType = 4,
                    Name = "1 bed + 1 double bed"
                },
                new RoomType
                {
                    IdRoomType = 5,
                    Name = "1 double bed"
                });

            modelBuilder.Entity<Facilities>().HasData(
                new Facilities
                {
                    IdFacilities = 1,
                    Name = "Bathroom"
                },
                new Facilities
                {
                    IdFacilities = 2,
                    Name = "TV"

                },
                new Facilities
                {
                    IdFacilities = 3,
                    Name = "Balcony"
                },
                new Facilities
                {
                    IdFacilities = 4,
                    Name = "Kitchen"
                },
                new Facilities
                {
                    IdFacilities = 5,
                    Name = "Hairdryer"
                });

            modelBuilder.Entity<Service>().HasData(
                new Service
                {
                    IdService = 1,
                    Name = "Breakfast",
                    Price = 25
                },
                new Service
                {
                    IdService = 2,
                    Name = "All inclusive",
                    Price = 50

                });

            modelBuilder.Entity<Room>().HasData(
                new Room
                {
                    IdRoom = 1,
                    IdType = 1,
                    IsApartament = "no"
                });

            modelBuilder.Entity<Image>().HasData(
                new Image
                {
                    IdImage = 1,
                    IdRoom = 1,
                    Path = @"E:\Proiecte\Hotel\Hotel-WPF\Hotel-WPF\Resources\room1.jpg",
                    Name = "Camera 1"
                });

            modelBuilder.Entity<Offer>().HasData(
                new Offer
                {
                    IdOffer = 1,
                    Discount = 35,
                    StartDate = "20.12",
                    EndDate = "27.12",
                    Name = "Oferta Craciun"
                });

            modelBuilder.Entity<Price>().HasData(
                new Price
                {
                    IdPrice = 1,
                    MyPrice = 550,
                    StartDate = "01.01.2022",
                    EndDate = "01.06.2022",
                    IdRoomType = 1
                });

            modelBuilder.Entity<User>().HasData(
                new User
                {
                    IdUser = 1,
                    DateOfBirth = "12.07.1986",
                    Mail = "admin@gmail.com",
                    Name = "Administrator Sef",
                    PhoneNumber = "0755894682",
                    Password = "admin1234",
                    Surname = "Stefan",
                    IdRole = 1
                },
                new User
                {
                    IdUser = 2,
                    DateOfBirth = "15.12.1996",
                    Mail = "client234@gmail.com",
                    Name = "Dan",
                    PhoneNumber = "0755890000",
                    Password = "stef1234",
                    Surname = "Stefan",
                    IdRole = 2
                });

            modelBuilder.Entity<RoomFacilities>().HasData(
                new RoomFacilities
                {
                    IdFacilities = 1,
                    IdRoom = 1,
                    IdRoomFacilities = 2
                });

            modelBuilder.Entity<Reservation>().HasData(
                new Reservation
                {
                    IdReservation = 1,
                    IdOffer = 1,
                    IdUser = 2,
                    StartDate = "21.12.2021",
                    EndDate = "26.12.2021",
                    NrAdults = 2,
                    NrChildren = 1,
                    Status = "Achitat"
                });

            modelBuilder.Entity<ReservationService>().HasData(
                new ReservationService
                {
                    IdReservationService = 1,
                    IdReservation = 1,
                    IdService = 2,
                });

            modelBuilder.Entity<RoomReservation>().HasData(
                new RoomReservation
                {
                    IdRoomReservation = 1,
                    IdReservation = 1,
                    IdRoom = 1,
                });
        }
    }
}
