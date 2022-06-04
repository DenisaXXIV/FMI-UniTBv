using criptare.Server;
using criptare.Utility;

public class Program
{
    public static void Main(string[] args)
    {
        string opt = "a";
        while (true)
        {
            Console.WriteLine("If you want to exit please type Close, else press enter");
            opt = Console.ReadLine();
            if (opt == "Close")
            {
                break;
            }
            Console.WriteLine("Client operations:");
            Crypter.ReadKey();
            Crypter.ReadInput();
            Crypter.BreakInputIntoMatrix();
            /*for (int index = 0; index < Helper.CryptMatrix.Count; index++)
            {
                for (int index2 = 0; index2 < Helper.CryptMatrix[index].Count; index2++)
                {
                    Console.Write(Helper.CryptMatrix[index][index2] + " ");
                }
                Console.WriteLine();
            }*/
            Console.WriteLine("Client crypting result:");
            var crypted = Crypter.ReturnCryptedMessage();
            Console.WriteLine(crypted);
            Console.WriteLine("Connecting to server....");
            Thread.Sleep(4500);
            Console.Clear();
            Console.WriteLine("\n\n\n\n--------SERVER----------\n\n\n");
            //Server
            Decrypting.CryptedMessage = crypted;
            Decrypting.CharsToBeDeleted = Crypter.SurplusChars;
            Decrypting.Key = Crypter.Key;
            var decrypted = Decrypting.Decrypt();
            Console.WriteLine(decrypted);
            Thread.Sleep(5000);
            Console.Clear();
        }
    }
}
