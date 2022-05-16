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
        static void Main(string[] args)
        {
            string filepath = "C:\\Users\\yamsh\\Desktop\\lab5.txt";

            StreamReader reader = null;
            try
            {
                reader = new StreamReader(filepath);

                string content = reader.ReadToEnd();

                Console.WriteLine(content);
            }
            catch (Exception exc)
            {
                Console.WriteLine("File exception: " + exc.Message);
            }
            finally
            {
                if (reader != null) reader.Close();
            }

            Console.ReadKey();
        }
    }
}
