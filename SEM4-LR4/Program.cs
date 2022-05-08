using System;
using System.IO;
using System.Linq;

namespace TestLabNET
{
    internal class Program
    {
        static readonly char[] SENTENSE_SEPARATORS = { '.', '!', '?', ':', ';' };

        static void Main(string[] args)
        {
            string filepath = "C:\\Users\\yamsh\\Desktop\\test.txt";
            Console.WriteLine("Путь к файлу:");
            Console.WriteLine(filepath);

            StreamReader reader = null;
            try
            {
                reader = new StreamReader(filepath);

                string content = reader.ReadToEnd();

                Console.WriteLine("\nСодержимое файла:");
                Console.WriteLine(content);

                string[] sentences = content.Split(SENTENSE_SEPARATORS, StringSplitOptions.RemoveEmptyEntries);

                Console.WriteLine("\nПредложения, не содержащие запятых:");
                foreach (string sentence in sentences)
                {
                    if (!sentence.Contains(','))
                        Console.WriteLine($"{sentence.Trim()}.");
                }

            }
            catch (Exception ex)
            {
                Console.WriteLine("\n" + ex.Message);
            }
            finally
            {
                if (reader != null) reader.Close();
            }

            Console.ReadKey();
        }
    }
}
