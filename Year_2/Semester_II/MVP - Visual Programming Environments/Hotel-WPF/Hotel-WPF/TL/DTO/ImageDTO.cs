using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hotel_WPF.TL.DTO
{
    public class ImageDTO
    {
        public int IdImage { get; set; }
        public string Name { get; set; }
        public string Path { get; set; }
        public int IdRoom { get; set; }
    }
}
