using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hotel_WPF.DAL.Entities
{
    public class RoomType
    {
        [Required]
        [Key]
        public int IdRoomType { get; set; }

        [Required(ErrorMessage = "Name is required!")]
        public string Name { get; set; }
    }
}
