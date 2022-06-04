using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hotel_WPF.DAL.Entities
{
    public class Offer
    {
        [Required]
        [Key]
        public int IdOffer { get; set; }

        [Required(ErrorMessage = "Name is required!")]
        public string Name { get; set; }

        [Required(ErrorMessage = "Discount is required!")]
        public int Discount { get; set; }

        [Required(ErrorMessage = "Start date is required!")]
        public string StartDate { get; set; }

        [Required(ErrorMessage = "End date is required!")]
        public string EndDate { get; set; }
    }
}
