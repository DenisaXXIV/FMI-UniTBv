// See https://aka.ms/new-console-template for more information
using FereastraGlisanta;

namespace fereastra_glisanta
{
    class Program
    {
        static void Main(string[] args)
        {
            string mesaj = Console.ReadLine();
            AlgoritmFereastraGlisanta algoritm = new AlgoritmFereastraGlisanta(mesaj);
        }
    }
}
