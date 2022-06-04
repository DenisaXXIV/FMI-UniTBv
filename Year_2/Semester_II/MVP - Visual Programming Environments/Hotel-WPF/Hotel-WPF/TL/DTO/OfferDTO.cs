using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hotel_WPF.TL.DTO
{
    public class OfferDTO
    {
        public int IdOffer { get; set; }
        public string Name { get; set; }
        public int Discount { get; set; }
        public string StartDate { get; set; }
        public string EndDate { get; set; }
    }
}
