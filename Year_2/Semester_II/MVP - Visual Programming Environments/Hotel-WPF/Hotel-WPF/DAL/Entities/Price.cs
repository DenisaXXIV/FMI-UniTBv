using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hotel_WPF.DAL.Entities
{
    public class Price
    {
        [Required]
        [Key]
        public int IdPrice { get; set; }

        [Required(ErrorMessage = "Price is required!")]
        public float MyPrice { get; set; }

        [Required(ErrorMessage = "StartDate is required!")]
        public string StartDate { get; set; }

        [Required(ErrorMessage = "EndDate is required!")]
        public string EndDate { get; set; }

        [Required(ErrorMessage = "RoomType is required!")]
        [ForeignKey("RoomType")]
        public int IdRoomType { get; set; }
    }
}
