using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FereastraGlisanta
{
    internal class AlgoritmFereastraGlisanta
    {
        private Thread _threadSursa;
        private Thread _threadDestinatie;
        private bool ACK { get; set; }
        private bool FIN { get; set; } = false;
        private int Pozitie { get; set; } = 0;
        private int DestinatieDim { get; set; }
        private string Buffer { get; set; }
        private string MemorieSursa { get; set; }
        public string MemorieDestinatie { get; set; }
        public bool MesajIntermediar { get; set; } = false;

        public AlgoritmFereastraGlisanta(string raspuns)
        {
            ACK = false;
            MemorieSursa = raspuns;
            _threadSursa = new Thread(() => FunctieSursa());
            _threadDestinatie = new Thread(() => RecieveFunction());
            _threadSursa.Start();
            _threadDestinatie.Start();
            _threadSursa.Join();
            _threadDestinatie.Join();
        }

        private int GenerareF()
        {
            Random random = new Random();
            int valueRandom = random.Next(0, 5);

            while (valueRandom == 0)
                valueRandom = random.Next(0, 5);
            return valueRandom;
        }

        private void FunctieSursa()
        {
            if (FIN == true)
            {
                return;
            }
            if (ACK == false)
            {
                try
                {
                    Thread.Sleep(500);
                }
                catch (ThreadInterruptedException)
                {
                    FunctieSursa();
                }
                return;
            }

            if (ACK == true && MesajIntermediar == false)
            {
                Console.WriteLine("Mesaje intermediare: ");
                MesajIntermediar = true;
            }

            if (Pozitie + DestinatieDim < MemorieSursa.Length)
            {
                Buffer = MemorieSursa.Substring(Pozitie, DestinatieDim);
                Pozitie += DestinatieDim;
            }
            else
            {
                Buffer = MemorieSursa.Substring(Pozitie);
                FIN = true;
            }
            Console.WriteLine("*** Sursa se opreste si este pornita Destinatia ***");
            _threadDestinatie.Interrupt();
            try
            {
                Thread.Sleep(500);
            }
            catch (ThreadInterruptedException)
            {
                FunctieSursa();
            }

        }

        private void RecieveFunction()
        {
            if (Buffer != "")
            {

                if (FIN == true)
                {
                    MemorieDestinatie += Buffer;
                    Console.WriteLine("\n\n\n --> Mesaj final primit de Destinatie: " + MemorieDestinatie);
                    return;
                }
                if (ACK == false)
                {
                    ACK = true;
                    Console.WriteLine("\n*** Conexiune acceptata ***\n");
                }
                else
                {
                    MemorieDestinatie += Buffer;
                    Console.WriteLine(MemorieDestinatie);

                }

                DestinatieDim = GenerareF();
                Console.WriteLine("*** Destinatia se opreste sieste pornita din nou Sursa *** \nF-ul trimis este : " + DestinatieDim);
                _threadSursa.Interrupt();
                try
                {
                    Thread.Sleep(500);
                }
                catch (ThreadInterruptedException)
                {
                    RecieveFunction();
                }
            }
            else
            {
                Console.WriteLine("\n*** Recieverul nu are connexiune ***\n");
                RecieveFunction();
            }
        }
    }
}
