using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace Hotel_WPF.DAL.Migrations
{
    public partial class Values : Migration
    {
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.AlterColumn<int>(
                name: "IdRoom",
                table: "RoomReservations",
                type: "int",
                nullable: false,
                oldClrType: typeof(string),
                oldType: "nvarchar(max)");

            migrationBuilder.AlterColumn<int>(
                name: "IdReservation",
                table: "RoomReservations",
                type: "int",
                nullable: false,
                oldClrType: typeof(string),
                oldType: "nvarchar(max)");

            migrationBuilder.InsertData(
                table: "Images",
                columns: new[] { "IdImage", "IdRoom", "Name", "Path" },
                values: new object[] { 1, 1, "Camera 1", "E:\\Proiecte\\Hotel\\Hotel-WPF\\Hotel-WPF\\Resources\\room1.jpg" });

            migrationBuilder.InsertData(
                table: "Offers",
                columns: new[] { "IdOffer", "Discount", "EndDate", "Name", "StartDate" },
                values: new object[] { 1, 35, "27.12", "Oferta Craciun", "20.12" });

            migrationBuilder.InsertData(
                table: "Prices",
                columns: new[] { "IdPrice", "EndDate", "IdRoomType", "MyPrice", "StartDate" },
                values: new object[] { 1, "01.06.2022", 1, 550f, "01.01.2022" });

            migrationBuilder.InsertData(
                table: "ReservationServices",
                columns: new[] { "IdReservationService", "IdReservation", "IdService" },
                values: new object[] { 1, 1, 2 });

            migrationBuilder.InsertData(
                table: "Reservations",
                columns: new[] { "IdReservation", "EndDate", "IdOffer", "IdUser", "NrAdults", "NrChildren", "StartDate", "Status" },
                values: new object[] { 1, "26.12.2021", 1, 2, 2, 1, "21.12.2021", "Achitat" });

            migrationBuilder.InsertData(
                table: "RoomFacilities",
                columns: new[] { "IdRoomFacilities", "IdFacilities", "IdRoom" },
                values: new object[] { 2, 1, 1 });

            migrationBuilder.InsertData(
                table: "RoomReservations",
                columns: new[] { "IdRoomReservation", "IdReservation", "IdRoom" },
                values: new object[] { 1, 1, 1 });

            migrationBuilder.InsertData(
                table: "Users",
                columns: new[] { "IdUser", "DateOfBirth", "IdRole", "Mail", "Name", "Password", "PhoneNumber", "Surname" },
                values: new object[,]
                {
                    { 1, "12.07.1986", 1, "admin@gmail.com", "Administrator Sef", "admin1234", "0755894682", "Stefan" },
                    { 2, "15.12.1996", 2, "client234@gmail.com", "Dan", "stef1234", "0755890000", "Stefan" }
                });
        }

        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DeleteData(
                table: "Images",
                keyColumn: "IdImage",
                keyValue: 1);

            migrationBuilder.DeleteData(
                table: "Offers",
                keyColumn: "IdOffer",
                keyValue: 1);

            migrationBuilder.DeleteData(
                table: "Prices",
                keyColumn: "IdPrice",
                keyValue: 1);

            migrationBuilder.DeleteData(
                table: "ReservationServices",
                keyColumn: "IdReservationService",
                keyValue: 1);

            migrationBuilder.DeleteData(
                table: "Reservations",
                keyColumn: "IdReservation",
                keyValue: 1);

            migrationBuilder.DeleteData(
                table: "RoomFacilities",
                keyColumn: "IdRoomFacilities",
                keyValue: 2);

            migrationBuilder.DeleteData(
                table: "RoomReservations",
                keyColumn: "IdRoomReservation",
                keyValue: 1);

            migrationBuilder.DeleteData(
                table: "Users",
                keyColumn: "IdUser",
                keyValue: 1);

            migrationBuilder.DeleteData(
                table: "Users",
                keyColumn: "IdUser",
                keyValue: 2);

            migrationBuilder.AlterColumn<string>(
                name: "IdRoom",
                table: "RoomReservations",
                type: "nvarchar(max)",
                nullable: false,
                oldClrType: typeof(int),
                oldType: "int");

            migrationBuilder.AlterColumn<string>(
                name: "IdReservation",
                table: "RoomReservations",
                type: "nvarchar(max)",
                nullable: false,
                oldClrType: typeof(int),
                oldType: "int");
        }
    }
}
