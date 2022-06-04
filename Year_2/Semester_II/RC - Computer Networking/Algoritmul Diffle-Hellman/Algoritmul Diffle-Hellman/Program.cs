using System;
using System.Text;
using System.Net;
using System.Net.Sockets;

namespace Algoritmul_Diffle_Hellman
{
    public class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Server starting !");

            IPAddress ipAddr = IPAddress.Loopback;

            int port = 8081;

            IPEndPoint ep = new IPEndPoint(ipAddr, port);

            TcpListener listener = new TcpListener(ep);
            listener.Start();

            Console.WriteLine("Server listening on: {0}:{1}", ep.Address, ep.Port);

            var messagesReceived = 0;
            string p = "13", a = "6", publicKey = "2", messageEncrypted = "abd";
            var key = GenerateKey();

            while (true)
            {
                var sender = listener.AcceptTcpClient();
                string request = streamToMessage(sender.GetStream());
                messagesReceived++;
                if (request != null)
                {

                    switch (messagesReceived % 4)
                    {
                        case 1:
                            p = request;

                            while (int.Parse(key) >= int.Parse(p))
                            {
                                key = GenerateKey();
                            }

                            Console.WriteLine("Private Key :" + key);
                            break;
                        case 2:
                            a = request;
                            break;
                        case 3:
                            publicKey = request;
                            sendMessage((Math.Pow(int.Parse(a), int.Parse(key)) % int.Parse(p)).ToString(), sender);
                            break;
                        case 0:
                            messageEncrypted = request;
                            DiffieHellman(p, a, publicKey, messageEncrypted, key);
                            break;

                    }
                    sendMessage("ok", sender);
                }
            }


        }

        public static string GenerateKey()
        {
            var rand = new Random();
            string key = rand.Next(10).ToString();
            return key;
        }

        private static void sendMessage(string message, TcpClient client)
        {
            byte[] bytes = messageToByteArray(message);
            client.GetStream().Write(bytes, 0, bytes.Length);
        }

        public static void DiffieHellman(string p, string a, string publicKey, string message, string key)
        {
            var SharedKey = (Math.Pow(int.Parse(publicKey), int.Parse(key)) % int.Parse(p)).ToString();
            Console.WriteLine("Enciphered mesaage: \n" + message + '\n');

            Console.WriteLine("Deciphered mesaage: \n" + Decipher(message, int.Parse(SharedKey)) + '\n');

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

        public static string Decipher(string input, int key)
        {
            return Encipher(input, 26 - key);
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



    }
}