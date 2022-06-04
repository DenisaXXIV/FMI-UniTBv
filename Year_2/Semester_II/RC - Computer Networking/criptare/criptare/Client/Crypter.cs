using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace criptare.Utility
{
    internal static class Crypter
    {
        public static string Key { get; set; }
        public static string Input { get; set; }
        public static List<List<char>> CryptMatrix { get; set; } = new List<List<char>>();
        public static char[] alpha = "abcdefghijklmnopqrstuvxwz".ToCharArray();
        public static int SurplusChars { get; set; } = 0;
        public static void ReadKey()
        {
            do
            {
                Console.WriteLine("Key:");
                Key = Console.ReadLine();
            } while (!IsKeyValid());
        }

        public static void ReadInput()
        {
            do
            {
                Console.WriteLine("Input:");
                Input = Console.ReadLine();
            } while (!IsInputValid());
        }

        public static bool IsInputValid()
        {
            return !string.IsNullOrEmpty(Input);
        }

        public static bool IsKeyValid()
        {
            HashSet<char> testSet = new HashSet<char>(Key.ToCharArray());
            return testSet.Count == Key.Length;
        }

        public static void BreakInputIntoMatrix()
        {
            int index = 0;
            while (index < Input.Length)
            {
                var list = new List<char>();
                int alphIndex = 0;
                for (int keyIndex = 0; keyIndex < Key.Length; keyIndex++)
                {
                    if (index == Input.Length)
                    {
                        list.Add(alpha[alphIndex++]);
                        SurplusChars++;
                        continue;
                    }
                    if (char.IsWhiteSpace(Input[index]))
                    {
                        list.Add('_');
                        index++;
                        continue;
                    }
                    list.Add(Input[index]);
                    index++;
                }
                CryptMatrix.Add(list);
            }
        }

        public static string SortKey()
        {
            return string.Concat(Key.OrderBy(s => s));
        }

        public static string ReturnCryptedMessage()
        {
            StringBuilder sb = new StringBuilder();
            var sortedKey = SortKey();
            int sortedIndex = 0;
            for (int index1 = 0; index1 < Key.Length; index1++)
            {
                var currentIndex = Key.IndexOf(sortedKey[sortedIndex]);
                for (int index2 = 0; index2 < CryptMatrix.Count; index2++)
                {
                    sb.Append(CryptMatrix[index2][currentIndex]);
                }
                sortedIndex++;
            }
            return sb.ToString();
        }
    }
}
