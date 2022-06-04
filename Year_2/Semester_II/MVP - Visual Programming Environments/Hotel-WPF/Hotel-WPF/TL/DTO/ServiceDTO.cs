using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hotel_WPF.TL.DTO
{
    public class ServiceDTO
    {
        public int IdService { get; set; }
        public string Name { get; set; }
        public float Price { get; set; }

    }
}
