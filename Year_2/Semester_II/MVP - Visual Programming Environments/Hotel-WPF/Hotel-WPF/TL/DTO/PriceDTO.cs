using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hotel_WPF.TL.DTO
{
    public class PriceDTO
    {
        public int IdPrice { get; set; }
        public float MyPrice { get; set; }
        public string StartDate { get; set; }
        public string EndDate { get; set; }
        public int IdRoomType { get; set; }
    }
}
