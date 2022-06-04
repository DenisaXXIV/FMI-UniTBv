using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hotel_WPF.DAL.Entities
{
    public class Employee
    {
        [Required]
        [Key]
        public int IdEmployee { get; set; }

        [Required(ErrorMessage = "Date of employment is required!")]
        public string DateOfEmployment { get; set; }

        [Required(ErrorMessage = "Date of resignation is required!")]
        public string DateOfResignation { get; set; }

        [Required(ErrorMessage = "Employee position is required!")]
        [ForeignKey("EmployeePosition")]
        public int IdEmployeePosition { get; set; }

        [Required(ErrorMessage = "User is required!")]
        [ForeignKey("User")]
        public int IdUser { get; set; }
    }
}
