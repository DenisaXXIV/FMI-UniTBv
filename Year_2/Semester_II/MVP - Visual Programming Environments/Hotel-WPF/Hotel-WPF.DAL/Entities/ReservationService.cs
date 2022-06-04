using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hotel_WPF.DAL.Entities
{
    public class ReservationService
    {
        [Required]
        [Key]
        public int IdReservationService { get; set; }

        [Required(ErrorMessage = "Reservation is required!")]
        [ForeignKey("Reservation")]
        public int IdReservation { get; set; }

        [Required(ErrorMessage = "Service is required!")]
        [ForeignKey("Service")]
        public int IdService { get; set; }
    }
}
