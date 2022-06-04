using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hotel_WPF.TL.DTO
{
    public class ReservationDTO
    {
        public int IdReservation { get; set; }
        public int IdUser { get; set; }
        public string StartDate { get; set; }
        public string EndDate { get; set; }
        public int NrAdults { get; set; }
        public int NrChildren { get; set; }
        public int IdOffer { get; set; }
        public string Status { get; set; }
    }
}
