using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hotel_WPF.DAL.Entities
{
    public class UserPermission
    {
        [Required]
        [Key]
        public int IdUserPermission { get; set; }

        [Required(ErrorMessage = "User is required!")]
        [ForeignKey("User")]
        public int IdUser { get; set; }

        [Required(ErrorMessage = "Permission is required!")]
        [ForeignKey("Permission")]
        public int IdPermission { get; set; }
    }
}
