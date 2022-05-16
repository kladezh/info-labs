using System;
using System.IO;
using System.Text.RegularExpressions;

using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SEM4_LR5
{
    internal class Program
    {
        static string ReadFileContent(string filepath)
        {
            StreamReader reader = null;
            try
            {
                reader = new StreamReader(filepath);
                return reader.ReadToEnd();
            }
            catch (Exception exc)
            {
                Console.WriteLine("File exception: " + exc.Message);
                return null;
            }
            finally
            {
                if (reader != null) reader.Close();
            }
        }

        static void Task1()
        {
            string filepath = "C:\\Users\\yamsh\\Desktop\\lab5.txt";
            string content = ReadFileContent(filepath);

            string[] lines = content.Split('\n');

            Console.WriteLine("Строки файла:");
            for (int i = 0; i < lines.Length; i++)
            {
                Console.WriteLine($"[{i}] => " + lines[i]);
            }

            Regex regex = new Regex("\\*");

            List<int> matchesLineIndexes = new List<int>();
            for (int i = 0; i < lines.Length; i++)
            {
                if (regex.IsMatch(lines[i]))
                {
                    matchesLineIndexes.Add(i);
                }
            }

            Console.WriteLine("\nНомера строк, в которых встречается символ \'*\'");
            foreach (int i in matchesLineIndexes)
                Console.WriteLine(i);
        }
        static void Main(string[] args)
        {
            Task1();

            Console.ReadKey();
        }
    }
}
