public class Program
{
    private static void ReadString(List<string> myString)
    {
        Console.WriteLine("Introduceti mesajul initial:");
        string word = Console.ReadLine();
        myString.Add(word);
    }

    private static bool VerifyString(List<string> myString)
    {
        int ok = 0;

        for (int index = 0; index < myString.Count; index++)
        {
            foreach (var letter in myString[index])
            {
                if (Char.IsLetter(letter) || Char.IsWhiteSpace(letter))
                {
                    ok = 1;
                    continue;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }

    private static List<List<long>> TransformToBinary(List<string> myString)
    {
        var binaryValues = new List<List<long>>();

        for (int index = 0; index < myString.Count; index++)
        {
            for (int index2 = 0; index2 < myString[index].Length; index2++)
            {
                List<long> list = new List<long>();

                int ASCII = (int)(myString[index][index2]);

                while (ASCII > 0)
                {
                    if (ASCII % 2 == 0)
                    {
                        list.Add(0);
                    }
                    else
                        if (ASCII % 2 == 1)
                    {
                        list.Add(1);
                    }
                    ASCII = ASCII / 2;
                }

                if (myString[index][index2] == ' ')
                {
                    list.Add(0);
                }
                binaryValues.Add(list);
                binaryValues.Reverse();
            }
        }
        return binaryValues;
    }

    private static List<long> ParityBytes(List<List<long>> binaries)
    {
        List<long> parityVector = new List<long>();

        for (int index = 0; index < binaries.Count; index++)
        {
            int parityCount = 0;
            for (int index2 = 0; index2 < binaries[index].Count; index2++)
            {
                if (binaries[index][index2] == 1)
                {
                    parityCount++;
                }
            }
            if (parityCount % 2 == 0)
            {
                parityVector.Add(0);
            }
            if (parityCount % 2 == 1)
            {
                parityVector.Add(1);
            }
        }
        return parityVector;
    }

    private static List<long> ResultVector(List<List<long>> binaries)
    {
        List<long> result = new List<long>();
        int length = 7;

        for (int index2 = 0; index2 < length; index2++)
        {
            int counter = 0;

            for (int index = 0; index < binaries.Count; index++)
            {
                counter += (int)binaries[index][index2];
            }

            if (counter % 2 == 0)
            {
                result.Add(0);
            }
            if (counter % 2 == 1)
            {
                result.Add(1);
            }
        }
        return result;
    }

    private static int Parity(List<long> result)
    {
        int parity = 0;
        int counter = 0;
        for (int index = 0; index < result.Count; index++)
        {
            if (result[index] == 1)
            {
                counter++;
            }
        }
        if (counter % 2 == 0)
        {
            parity = 0;
        }
        if (counter % 2 == 1)
        {
            parity = 1;
        }
        return parity;
    }

    private static void CorruptedMessage(List<List<long>> binaries)
    {
        Random random = new Random();
        int randomCollumn = random.Next(0, 7);
        int randomLine = random.Next(0, binaries.Count);

        for (int index = 0; index < binaries.Count; index++)
        {
            for (int index2 = 0; index2 < binaries[index].Count; index2++)
            {
                if (index == randomLine && index2 == randomCollumn)
                {
                    if (binaries[index][index2] == 0)
                    {
                        binaries[index][index2] = 1;
                    }
                    if (binaries[index][index2] == 1)
                    {
                        binaries[index][index2] = 0;
                    }
                }
            }
        }
    }

    private static void ParityRecalculatin(List<List<long>> binary, List<long> parityVector, List<long> result)
    {
        int corruptedLine = 0;
        int corruptedCollumn = 0;

        for (int index = 0; index < binary.Count; index++)
        {
            int parityCounter = 0;
            for (int index2 = 0; index2 < binary[index].Count; index2++)
            {
                if (binary[index][index2] == 1)
                {
                    parityCounter++;
                }
            }
            if (parityCounter % 2 == parityVector[index])
            {
                continue;
            }
            corruptedLine = index;
        }
        for (int index = 0; index < 7; index++)
        {
            int parityCounter = 0;
            for (int index2 = 0; index2 < binary.Count; index2++)
            {
                if (binary[index2][index] == 1)
                {
                    parityCounter++;
                }
            }
            if (parityCounter % 2 == result[index])
            {
                continue;
            }
            corruptedCollumn = index;
        }
        Console.WriteLine(corruptedLine + " " + corruptedCollumn + "\n");
    }

    private static void Print(List<List<long>> binary)
    {
        var parityVector = ParityBytes(binary);
        for (int index = 0; index < binary.Count; index++)
        {
            for (int index2 = 0; index2 < binary[index].Count; index2++)
            {
                Console.Write(binary[index][index2]);
            }
            Console.WriteLine(" " + parityVector[index]);
        }
        Console.WriteLine(".................");
    }

    private static void PrintResult(List<List<long>> binary, List<long> result)
    {
        int semnificativeByte = Parity(result);
        for (int index = 0; index < result.Count; index++)
        {
            Console.Write(result[index]);
        }
        Console.WriteLine(" " + semnificativeByte);
    }
    public static void Main(string[] args)
    {
        List<string> message = new List<string>();
        ReadString(message);

        List<List<long>> binary = new List<List<long>>();

        if (VerifyString(message))
        {
            binary = TransformToBinary(message);
        }

        List<long> parityVector = new List<long>();
        parityVector = ParityBytes(binary);
        List<long> result = new List<long>();
        result = ResultVector(binary);

        Print(binary);
        PrintResult(binary, result);

        Console.WriteLine();

        CorruptedMessage(binary);
        Print(binary);
        PrintResult(binary, result);
        ParityRecalculatin(binary, parityVector, result);
    }
}