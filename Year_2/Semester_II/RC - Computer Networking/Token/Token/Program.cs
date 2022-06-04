using System.Collections.Generic;
using Token.Utility;

public class Program
{
    public static void Main(string[] args)
    {
        Helper hp = new Helper();
        List<KeyValuePair<string, string>> calculatoare = hp.GenerareCalculatoare();
        hp.Parcurgere(calculatoare);
    }

}