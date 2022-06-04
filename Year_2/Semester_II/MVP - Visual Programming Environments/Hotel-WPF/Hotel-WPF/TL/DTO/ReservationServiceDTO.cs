using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hotel_WPF.TL.DTO
{
    public class ReservationServiceDTO
    {
        public int IdReservationService { get; set; }
        public int IdReservation { get; set; }
        public int IdService { get; set; }
    }
}
