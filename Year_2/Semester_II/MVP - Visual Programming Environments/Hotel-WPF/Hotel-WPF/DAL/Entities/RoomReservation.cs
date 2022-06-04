using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hotel_WPF.DAL.Entities
{
    public class RoomReservation
    {
        [Required]
        [Key]
        public int IdRoomReservation { get; set; }

        [Required(ErrorMessage = "Room is required!")]
        [ForeignKey("Room")]
        public int IdRoom { get; set; }

        [Required(ErrorMessage = "Reservation is required!")]
        [ForeignKey("Reservation")]
        public int IdReservation { get; set; }
    }
}
