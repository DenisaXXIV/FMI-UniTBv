using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hotel_WPF.DAL.Entities
{
    public class Reservation
    {
        [Required]
        [Key]
        public int IdReservation { get; set; }

        [Required(ErrorMessage = "Client is required!")]
        [ForeignKey("Client")]
        public int IdClient { get; set; }

        [Required(ErrorMessage = "StartDate is required!")]
        public string StartDate { get; set; }

        [Required(ErrorMessage = "EndDate is required!")]
        public string EndDate { get; set; }

        [Required(ErrorMessage = "Number of adults is required!")]
        public int NrAdults { get; set; }

        [Required(ErrorMessage = "Number of children is required!")]
        public int NrChildren { get; set; }

        [Required(ErrorMessage = "Offer is required!")]
        [ForeignKey("Offer")]
        public int IdOffer { get; set; }

        [Required(ErrorMessage = "Payment is required!")]
        [ForeignKey("Payment")]
        public int IdPayment { get; set; }

        [Required(ErrorMessage = "Room is required!")]
        [ForeignKey("Room")]
        public int IdRoom { get; set; }
    }
}
