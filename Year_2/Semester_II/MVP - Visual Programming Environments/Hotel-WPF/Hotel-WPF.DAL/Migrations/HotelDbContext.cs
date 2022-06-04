using Hotel_WPF.DAL.Entities;
using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hotel_WPF.DAL.Migrations
{
    public class HotelDbContext : DbContext
    {
        //private const string CONNECTION_STRING = "Server=(localdb)\\MSSQLLocalDB;Database=HotelDB;Trusted_Connection=True;MultipleActiveResultSets=true";
        public HotelDbContext() : base("name=HotelDbString")
        {

        }

        public DbSet<Address> Address { get; set; }
        public DbSet<Client> Clients { get; set; }
        public DbSet<Employee> Employees { get; set; }
        public DbSet<EmployeePosition> EmployeePositions { get; set; }
        public DbSet<Facilities> Facilities { get; set; }
        public DbSet<Image> Images { get; set; }
        public DbSet<Offer> Offers { get; set; }
        public DbSet<Payment> Payments { get; set; }
        public DbSet<Permission> Permissions { get; set; }
        public DbSet<Reservation> Reservations { get; set; }
        public DbSet<ReservationService> ReservationServices { get; set; }
        public DbSet<Role> Roles { get; set; }
        public DbSet<Room> Rooms { get; set; }
        public DbSet<RoomFacilities> RoomFacilities { get; set; }
        public DbSet<RoomType> RoomTypes { get; set; }
        public DbSet<Service> Services { get; set; }
        public DbSet<User> Users { get; set; }
        public DbSet<UserPermission> UserPermissions { get; set; }

        /*protected override void OnModelCreating(ModelBuilder modelBuilder)
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
                    Name = "1 bed",
                    OriginalPrice = 24,
                    CurrentPrice = 24
                },
                new RoomType
                {
                    IdRoomType = 2,
                    Name = "2 beds",
                    OriginalPrice = 48,
                    CurrentPrice = 48

                },
                new RoomType
                {
                    IdRoomType = 3,
                    Name = "3 beds",
                    OriginalPrice = 72,
                    CurrentPrice = 72
                },
                new RoomType
                {
                    IdRoomType = 4,
                    Name = "1 bed + 1 double bed",
                    OriginalPrice = 48,
                    CurrentPrice = 48
                },
                new RoomType
                {
                    IdRoomType = 5,
                    Name = "1 double bed",
                    OriginalPrice = 48,
                    CurrentPrice = 48
                });

            modelBuilder.Entity<Facilities>().HasData(
                new Facilities
                {
                    IdFacilities = 1,
                    Name = "Bathroom",
                    Price = 5
                },
                new Facilities
                {
                    IdFacilities = 2,
                    Name = "TV",
                    Price = 3

                },
                new Facilities
                {
                    IdFacilities = 3,
                    Name = "Balcony",
                    Price = 5
                },
                new Facilities
                {
                    IdFacilities = 4,
                    Name = "Kitchen",
                    Price = 15
                },
                new Facilities
                {
                    IdFacilities = 5,
                    Name = "Hairdryer",
                    Price = 2
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
        }*/
    }
}
