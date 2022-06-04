using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Token.Model;

namespace Token.Utility
{
    internal class Helper
    {
        public string randomIP()
        {
            StringBuilder IP = new StringBuilder();
            Random random = new Random();

            for (int i = 0; i < 4; i++)
            {
                IP.Append(random.Next(0, 255)).ToString();
                IP.Append(".");
            }
            IP.Remove(IP.Length - 1, 1);

            return IP.ToString();
        }

        public List<KeyValuePair<string, string>> GenerareCalculatoare()
        {
            List<KeyValuePair<string, string>> raspuns = new List<KeyValuePair<string, string>>();
            for (int i = 0; i < 10; i++)
            {
                raspuns.Add(new KeyValuePair<string, string>(randomIP(), "null"));
            }
            return raspuns;
        }

        public Model.Token CreareToken(List<KeyValuePair<string, string>> calculatoare)
        {

            string IPSursa, IPDestinatie;
            Random random = new Random();

            do
            {
                IPSursa = calculatoare[random.Next(0, calculatoare.Count)].Key;
                IPDestinatie = calculatoare[random.Next(0, calculatoare.Count)].Key;


            } while (IPSursa.CompareTo(IPDestinatie) == 0);
            Model.Token token = new Model.Token(IPSursa, IPDestinatie, "test");

            token.ajuns = false;
            token.liber = false;

            return token;
        }

        public void Parcurgere(List<KeyValuePair<string, string>> calculatoare)
        {
            Model.Token token = CreareToken(calculatoare);
            int calculatorDestinatie = 0, calculatorSursa = 0;


            Console.WriteLine("Lista cu toate calculatoarele:\n");
            for (int i = 0; i < calculatoare.Count; i++)
            {
                Console.WriteLine(calculatoare[i].Key + " " + calculatoare[i].Value + "\n");
                //ptr aflarea sursei
                if (token.sursa.CompareTo(calculatoare[i].Key) == 0)
                    calculatorSursa = i;
            }
            Console.WriteLine("\n\n");
            Console.WriteLine("Sursa:" + token.sursa + "    Destinatie:" + token.destinatie + "\n\n");


            int ok = 0;
            for (int i = calculatorSursa; i < calculatoare.Count; i++)
            {

                if (calculatoare[i].Key == token.destinatie)
                {
                    calculatorDestinatie = i;
                    token.ajuns = true;
                    calculatoare[i].Value.Replace(calculatoare[i].Key, token.mesaj);
                    Console.WriteLine(calculatoare[i].Key + " AM AJUNS LA DESTINATIE" + "\n");
                    ok = 1;
                    break;

                }
                else
                {

                    Console.WriteLine(calculatoare[i].Key + " Muta Jetonu" + "\n");
                }

            }
            if (ok == 0)
                for (int i = 0; i < calculatoare.Count; i++)
                {

                    if (calculatoare[i].Key == token.destinatie)
                    {
                        calculatorDestinatie = i;
                        token.ajuns = true;
                        calculatoare[i].Value.Replace(calculatoare[i].Key, token.mesaj);
                        Console.WriteLine(calculatoare[i].Key + " AM AJUNS LA DESTINATIE" + "\n");

                        break;

                    }
                    else
                    {

                        Console.WriteLine(calculatoare[i].Key + " Muta Jetonu" + "\n");
                    }

                }


            Console.WriteLine("\n");

            ok = 0;
            for (int i = calculatorDestinatie; i < calculatoare.Count; i++)
            {
                if (calculatoare[i].Key == token.sursa)
                {


                    token.liber = true;
                    Console.WriteLine(calculatoare[i].Key + " AM AJUNS LA SURSA" + "\n");
                    ok = 1;
                    break;
                }
                else
                {

                    Console.WriteLine(calculatoare[i].Key + " Muta Jetonu\n");
                }
            }
            if (ok == 0)
                for (int i = 0; i < calculatoare.Count; i++)
                {
                    if (calculatoare[i].Key == token.sursa)
                    {

                        token.liber = true;
                        Console.WriteLine(calculatoare[i].Key + " AM AJUNS LA SURSA\n");
                        break;
                    }
                    else
                    {

                        Console.WriteLine(calculatoare[i].Key + " Muta Jetonu\n");
                    }
                }


            //afisarea dupa
            Console.WriteLine("\nAfisare:\n");
            for (int i = 0; i < calculatoare.Count; i++)
            {
                Console.WriteLine(calculatoare[i].Key + " " + calculatoare[i].Value + "\n");
            }
        }
    }
}
