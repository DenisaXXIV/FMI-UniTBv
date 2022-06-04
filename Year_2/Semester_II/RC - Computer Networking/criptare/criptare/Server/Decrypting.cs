using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace criptare.Server
{
    internal static class Decrypting
    {
        public static string Key { get; set; }
        public static string CryptedMessage { get; set; }
        public static List<List<char>> DeCryptedMatrix { get; set; } = new List<List<char>>();
        public static Dictionary<char, List<char>> Dictionary { get; set; } = new Dictionary<char, List<char>>();
        public static int CharsToBeDeleted { get; set; }


        public static string Decrypt()
        {
            StringBuilder sb = new StringBuilder();
            int separatedCount = 0;
            if (CryptedMessage.Length % Key.Length == 0)
            {
                separatedCount = CryptedMessage.Length / Key.Length;
            }
            else
            {
                separatedCount = (CryptedMessage.Length / Key.Length) + 1;
            }
            var sortedKey = SortKey();
            int index = 0;
            int keyIndex = 0;
            var list = new List<char>();
            while (index < CryptedMessage.Length)
            {
                list.Add(CryptedMessage[index++]);
                if (index % separatedCount == 0)
                {
                    try
                    {
                        var aux = list;
                        Dictionary.Add(sortedKey[keyIndex], aux);
                        keyIndex++;
                        list = new List<char>();
                    }
                    catch (Exception ex)
                    {
                        Console.WriteLine(ex.ToString());
                    }
                }
            }

            foreach (var letter in Key)
            {
                DeCryptedMatrix.Add(Dictionary[letter]);
            }

            for (int index1 = 0; index1 < separatedCount; index1++)
            {
                for (int index2 = 0; index2 < DeCryptedMatrix.Count; index2++)
                {
                    sb.Append(DeCryptedMatrix[index2][index1]);
                    //Console.Write(DeCryptedMatrix[index2][index1] + " ");
                }
                //Console.WriteLine();
            }

            return FinalizeArray(sb);
        }
        public static string SortKey()
        {
            return string.Concat(Key.OrderBy(s => s));
        }

        public static string FinalizeArray(StringBuilder sb)
        {
            int count = sb.Length - CharsToBeDeleted;
            var initRes = sb.ToString();
            string finalRes = String.Empty;
            finalRes = initRes.Substring(0, count);

            return finalRes;
        }
    }
}
