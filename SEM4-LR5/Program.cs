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
            string content = ReadFileContent("fortask1.txt");

            string[] lines = content.Split(new string[] { Environment.NewLine }, 
                StringSplitOptions.RemoveEmptyEntries);

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

        static void Task2()
        {
            string content = ReadFileContent("fortask2.txt");

            List<string> lines = content.Split(new string[] { Environment.NewLine }, 
                StringSplitOptions.RemoveEmptyEntries)
                .ToList();

            Console.WriteLine("Строки файла:\n");
            foreach (string line in lines)
                Console.WriteLine(line);

            Regex regex = new Regex("[^a-zA-z]*\\d+[^a-zA-z]+");

            List<string> matchesLines = new List<string>();
            foreach (string line in lines)
            {
                if (regex.IsMatch(line))
                    matchesLines.Add(line);
            }

            Console.WriteLine("\nСтроки, в которых содержится в качестве слова целое число:\n");
            foreach (string line in matchesLines)
                Console.WriteLine(line);
        }

        static void Task3()
        {
            string content = ReadFileContent("fortask3.txt");

            Console.WriteLine("Строки файла:");
            Console.WriteLine(content + "\n");

            Regex regex = new Regex("(?<=\\().+?(?=\\))");

            string replacedContent = regex.Replace(content, new MatchEvaluator((Match match) =>
            {
                string value = match.ToString();

                Console.WriteLine("Match: " + value);

                return value[0].ToString();
            }));

            Console.WriteLine("\nИзмененные строки файла:");
            Console.WriteLine(replacedContent);
        }

        static void Main(string[] args)
        {
            //Task1();
            //Task2();
            //Task3();

            Console.ReadKey();
        }
    }
}
