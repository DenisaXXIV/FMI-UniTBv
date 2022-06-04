using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace Hotel_WPF.DAL.Migrations
{
    public partial class Rooms : Migration
    {
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.InsertData(
                table: "Rooms",
                columns: new[] { "IdRoom", "IdType", "IsApartament" },
                values: new object[] { 1, 1, "no" });
        }

        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DeleteData(
                table: "Rooms",
                keyColumn: "IdRoom",
                keyValue: 1);
        }
    }
}
