using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hotel_WPF.DAL.Entities
{
    public class Client
    {
        [Required]
        [Key]
        public int IdClient { get; set; }

        [Required(ErrorMessage = "Address is required!")]
        [ForeignKey("Address")]
        public int IdAddress { get; set; }

        [Required(ErrorMessage = "User is required!")]
        [ForeignKey("User")]
        public int IdUser { get; set; }
    }
}
