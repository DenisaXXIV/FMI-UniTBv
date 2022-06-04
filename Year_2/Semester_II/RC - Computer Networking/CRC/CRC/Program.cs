using System;
using System.Text;

namespace RCTema1
{
    class CRC
    {

        private static bool ValidateCode(string code, string polynom)
        {
            foreach (var current in code)
            {
                if (current != '0' && current != '1')
                {
                    Console.WriteLine("Error! There are non-binary values in the code!");
                    return false;
                }
            }

            if (code.Length <= polynom.Length)
            {
                Console.WriteLine("Error! The length of code MUST be greater than the length of polynom!");
                return false;
            }

            return true;
        }

        private static bool ValidatePolynom(string polynom)
        {
            if (polynom[0] != '1' || polynom[polynom.Length - 1] != '1')
            {
                Console.WriteLine("Error! The polynom MUST start and end with 1!");
                return false;
            }

            foreach (var current in polynom)
            {
                if (current != '0' && current != '1')
                {
                    Console.WriteLine("Error! There are non-binary values in the code!");
                    return false;
                }
            }

            return true;
        }

        private static string ExtendCode(string code, string polynom)
        {
            for (int index = 0; index < polynom.Length - 1; ++index)
            {
                code += '0';
            }

            return code;
        }

        private static string DoCRC(string extendedMessage, string polynomial)
        {
            short steps = 0;

            Console.WriteLine("\n CRC procces begins");

            while (extendedMessage.Length >= polynomial.Length)
            {
                Console.ForegroundColor = ConsoleColor.Green;

                Console.WriteLine("\nStep: " + steps++);

                Console.ForegroundColor = ConsoleColor.White;

                Console.WriteLine("Message: " + extendedMessage);
                Console.WriteLine("Polynom: " + polynomial);

                for (int iterator = 0; iterator < polynomial.Length; ++iterator)
                {
                    if (extendedMessage[iterator] == polynomial[iterator])
                    {
                        StringBuilder builder = new StringBuilder(extendedMessage);
                        builder[iterator] = '0';
                        extendedMessage = builder.ToString();
                    }
                    else
                    {
                        StringBuilder builder = new StringBuilder(extendedMessage);
                        builder[iterator] = '1';
                        extendedMessage = builder.ToString();
                    }
                }

                Console.WriteLine("Code is: " + extendedMessage);

                while (extendedMessage[0] == '0')
                {
                    if (extendedMessage.Length <= 0)
                    {
                        break;
                    }
                    string temp = extendedMessage;
                    extendedMessage = temp.Substring(1);
                }
            }

            Console.ForegroundColor = ConsoleColor.DarkGreen;

            Console.WriteLine("\nFinal code is: " + extendedMessage);

            if (extendedMessage.Length == 0)
            {
                return "0";
            }

            return extendedMessage;
        }

        private static string FindTransmittedCode(string extendedCode, string firstResult)
        {
            for (int iterator = 0; iterator < firstResult.Length; ++iterator)
            {
                StringBuilder builder = new StringBuilder(extendedCode);

                if (firstResult[firstResult.Length - iterator - 1] == '1')
                {
                    if (extendedCode[extendedCode.Length - iterator - 1] == '0')
                    {
                        builder[extendedCode.Length - iterator - 1] = '1';
                        extendedCode = builder.ToString();
                    }
                    else
                    {
                        builder[firstResult.Length - iterator - 1] = '0';
                        extendedCode = builder.ToString();
                    }
                }
            }

            return extendedCode;
        }

        private static void ModifyTransmittedCode(ref string transmittedCode)
        {
            Console.WriteLine("\nTransmitted code is: " + transmittedCode);

            Console.ForegroundColor = ConsoleColor.White;

            Console.WriteLine("\n\nDo you wish to change a bit? y/n");

            string choice = Console.ReadLine();

            switch (choice)
            {
                case "y":
                    Console.WriteLine("Choose the position of the bit");

                    int position = Convert.ToInt32(Console.ReadLine());

                    if (position > 0 && position < transmittedCode.Length)
                    {
                        StringBuilder builder = new StringBuilder(transmittedCode);

                        if (transmittedCode[position].Equals('0'))
                        {
                            builder[position] = '1';
                            transmittedCode = builder.ToString();
                        }
                        else
                        {
                            builder[position] = '0';
                            transmittedCode = builder.ToString();
                        }

                        Console.WriteLine("Done! New transmitted code is: " + transmittedCode);
                        Console.ReadKey();
                    }
                    else
                    {
                        Console.WriteLine("Invalid position!");
                    }
                    break;
                case "n":
                    Console.WriteLine("Nothing to change");
                    break;
                default:
                    Console.WriteLine("invalid option!");
                    break;
            }
        }

        private static void input()
        {
            string code;
            string polynom;

            Console.WriteLine("Input: ");
            code = Console.ReadLine();

            Console.WriteLine("Polynom: ");
            polynom = Console.ReadLine();

            if (ValidateCode(code, polynom) && ValidatePolynom(polynom))
            {
                solve(code, polynom);
            }
            else
            {
                return;
            }
        }

        private static void solve(string code, string polynom)
        {
            string extendedCode;
            string firstResult;
            string transmittedCode;
            string secondResult;

            extendedCode = ExtendCode(code, polynom);
            firstResult = DoCRC(extendedCode, polynom);
            transmittedCode = FindTransmittedCode(extendedCode, firstResult);

            ModifyTransmittedCode(ref transmittedCode);

            secondResult = DoCRC(transmittedCode, polynom);

            if (secondResult.Equals("0"))
            {
                Console.WriteLine("There was no error during the transmition!");
            }
            else
            {
                Console.WriteLine("There was an error during the tranmition! ");
            }
        }

        static void Main(string[] args)
        {
            input();
        }
    }
}
