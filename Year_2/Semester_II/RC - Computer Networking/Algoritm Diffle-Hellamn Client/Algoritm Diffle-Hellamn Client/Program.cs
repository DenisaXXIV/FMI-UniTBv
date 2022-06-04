using System;
using System.IO;
using System.Net;
using System.Text;
using System.Net.Sockets;
using System;
using System.IO;
using System.Net;
using System.Text;
using System.Net.Sockets;


public class Program
{

    static void Main(string[] args)
    {
        string requestMessage = "o";
        Console.WriteLine("Client starting !");

        Console.WriteLine("Client listening on: 127.0.0.1:8081 ");

        while (requestMessage != "x")
        {
            Console.WriteLine("Read p : ");
            string p = Console.ReadLine();

            while (!IsPrimeNr(int.Parse(p)))
            {
                Console.WriteLine("Read a prime p : ");
                p = Console.ReadLine();
            }

            string responseMessage = sendMessage(p);

            Console.WriteLine(responseMessage);

            Console.WriteLine("Read a : ");
            string a = Console.ReadLine();

            responseMessage = sendMessage(a);

            Console.WriteLine(responseMessage);

            string key = GenerateKey();
            while (int.Parse(key) >= int.Parse(p))
            {
                key = GenerateKey();
            }

            Console.WriteLine("Private Key : " + key);

            Console.WriteLine("Public Key : " + (Math.Pow(int.Parse(a), int.Parse(key)) % int.Parse(p)).ToString());

            responseMessage = sendMessage((Math.Pow(int.Parse(a), int.Parse(key)) % int.Parse(p)).ToString());

            Console.WriteLine("Public Key of Server : " + responseMessage);

            var ServerPublicKey = responseMessage;

            Console.WriteLine("Read message : ");
            requestMessage = Console.ReadLine();

            var SharedKey = (Math.Pow(int.Parse(ServerPublicKey), int.Parse(key)) % int.Parse(p)).ToString();

            responseMessage = sendMessage(Encipher(requestMessage, int.Parse(SharedKey)));
            Console.WriteLine(responseMessage);
        }
    }

    public static string GenerateKey()
    {
        var rand = new Random();
        string key = rand.Next(10).ToString();
        return key;
    }

    public static string sendMessage(string message)
    {
        string response = "";
        try
        {
            TcpClient client = new TcpClient("127.0.0.1", 8081);
            client.NoDelay = true;

            byte[] messageBytes = messageToByteArray(message);

            using (NetworkStream stream = client.GetStream())
            {
                stream.Write(messageBytes, 0, messageBytes.Length);

                response = streamToMessage(stream);
            }
            if (message == "x")
            {
                client.Close();
            }

        }
        catch (Exception e) { Console.WriteLine(e.Message); }
        return response;
    }

    static Encoding encoding = Encoding.UTF8;
    private static byte[] messageToByteArray(string message)
    {

        byte[] messageBytes = encoding.GetBytes(message);
        int messageSize = messageBytes.Length;

        int completeSize = messageSize + 4;

        byte[] completemsg = new byte[completeSize];


        byte[] sizeBytes = BitConverter.GetBytes(messageSize);

        sizeBytes.CopyTo(completemsg, 0);
        messageBytes.CopyTo(completemsg, 4);
        return completemsg;
    }

    private static string streamToMessage(Stream stream)
    {
        byte[] sizeBytes = new byte[4];
        stream.Read(sizeBytes, 0, 4);
        int messageSize = BitConverter.ToInt32(sizeBytes, 0);
        byte[] messageBytes = new byte[messageSize];
        stream.Read(messageBytes, 0, messageSize);
        string message = encoding.GetString(messageBytes);
        string result = null;
        foreach (var c in message)
            if (c != '\0')
                result += c;

        return result;
    }

    public static bool IsPrimeNr(int n)
    {
        for (int i = 2; i <= n / 2; i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }

    public static char cipher(char ch, int key)
    {
        if (!char.IsLetter(ch))
        {

            return ch;
        }

        char d = char.IsUpper(ch) ? 'A' : 'a';
        return (char)((((ch + key) - d) % 26) + d);


    }


    public static string Encipher(string input, int key)
    {
        string output = string.Empty;

        foreach (char ch in input)
            output += cipher(ch, key);

        return output;
    }
}