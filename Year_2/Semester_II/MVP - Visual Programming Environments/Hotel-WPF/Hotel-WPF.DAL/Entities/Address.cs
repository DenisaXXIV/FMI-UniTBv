using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hotel_WPF.DAL.Entities
{
    public class Address
    {
        [Required]
        [Key]
        public int IdAddress { get; set; }

        [Required(ErrorMessage = "City is required!")]
        public string City { get; set; }

        [Required(ErrorMessage = "Country is required!")]
        public string Country { get; set; }

        [Required(ErrorMessage = "Street is required!")]
        public string Street { get; set; }

        [Required(ErrorMessage = "Street number is required!")]
        public int StreetNumber { get; set; }
    }
}
