using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hotel_WPF.DAL.Entities
{
    public class Image
    {
        [Required]
        [Key]
        public int IdImage { get; set; }

        [Required(ErrorMessage = "Name is required!")]
        public string Name { get; set; }

        [Required(ErrorMessage = "Path is required!")]
        public string Path { get; set; }

        [Required(ErrorMessage = "Room is required!")]
        [ForeignKey("Room")]
        public int IdRoom { get; set; }
    }
}
