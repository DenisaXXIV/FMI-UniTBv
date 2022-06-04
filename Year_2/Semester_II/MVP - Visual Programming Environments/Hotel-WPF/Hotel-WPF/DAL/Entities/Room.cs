using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hotel_WPF.DAL.Entities
{
    public class Room
    {
        [Required]
        [Key]
        public int IdRoom { get; set; }

        [Required(ErrorMessage = "Room type is required!")]
        [ForeignKey("RoomType")]
        public int IdType { get; set; }

        [Required(ErrorMessage = "IsApartament is required!")]
        public string IsApartament { get; set; }
    }
}
