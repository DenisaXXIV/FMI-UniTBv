using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hotel_WPF.DAL.Entities
{
    public class User
    {
        [Required]
        [Key]
        public int IdUser { get; set; }

        [Required(ErrorMessage = "Role is required!")]
        [ForeignKey("Role")]
        public int IdRole { get; set; }

        [Required(ErrorMessage = "Mail is required!")]
        public string Mail { get; set; }

        [Required(ErrorMessage = "Password is required!")]
        public string Password { get; set; }

        [Required(ErrorMessage = "Name is required!")]
        public string Name { get; set; }

        [Required(ErrorMessage = "Surname is required!")]
        public string Surname { get; set; }

        [Required(ErrorMessage = "Phone number is required!")]
        public string PhoneNumber { get; set; }

        [Required(ErrorMessage = "Date of birth is required!")]
        public string DateOfBirth { get; set; }
    }
}
