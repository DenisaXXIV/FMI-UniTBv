using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hotel_WPF.DAL.Entities
{
    public class Payment
    {
        [Required]
        [Key]
        public int IdPayment { get; set; }

        [Required(ErrorMessage = "Status is required!")]
        public string Status { get; set; }

        [Required(ErrorMessage = "Reservation is required!")]
        [ForeignKey("Reservation")]
        public int IdReservation { get; set; }

        [Required(ErrorMessage = "Employee is required!")]
        [ForeignKey("Employee")]
        public int IdEmployee { get; set; }
    }
}
