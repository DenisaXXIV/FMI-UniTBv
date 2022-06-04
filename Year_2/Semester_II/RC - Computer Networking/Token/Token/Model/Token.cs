using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Token.Model
{
    public class Token
    {
        public string sursa { get; set; }
        public string destinatie { get; set; }
        public string mesaj { get; set; }
        public bool liber { get; set; }
        public bool ajuns { get; set; }

        public Token(string sursa, string destinatie, string mesaj)
        {
            this.sursa = sursa;
            this.destinatie = destinatie;
            this.mesaj = mesaj;
        }


    }
}
