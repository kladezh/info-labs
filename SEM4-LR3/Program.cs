using System;
using System.Linq;

namespace SEM4_LR3
{
    internal class Program
    {
        static void Task1()
        {
            Console.Write("Введите кол-во элементов массива: ");
            int arrCount = int.Parse(Console.ReadLine());

            int[] arr = new int[arrCount];

            Console.WriteLine("Введите элементы массива:");
            for (int i = 0; i < arr.Length; i++)
            {
                arr[i] = int.Parse(Console.ReadLine());
            }


            // Найти номер максимального по модулю элемента массива
            int iMax = 0;
            for (int i = 0; i < arr.Length; i++)
            {
                if (Math.Abs(arr[i]) > Math.Abs(arr[iMax]))
                    iMax = i;
            }

            Console.WriteLine("Номер макс. по модулю элемента: " + iMax);


            // Сумма элементов, расположенных после первого положительного
            int iFirstPos = 0;
            for (int i = 0; i < arr.Length; i++)
            {
                if (arr[i] > 0)
                {
                    iFirstPos = i;
                    break;
                }
            }

            int sum = 0;
            for (int i = iFirstPos + 1; i < arr.Length; i++)
            {
                sum += arr[i];
            }

            Console.WriteLine("\nПервый положительный элемент: " + arr[iFirstPos]);
            Console.WriteLine("Сумма элементов, после первого положительного: " + sum);


            // Преобразовать массив таким образом, чтобы сначала располагались все элементы, целая часть
            // которых лежит в интервале[а, b], а потом — все остальные.
            Console.Write("\nВведите a: ");
            int a = int.Parse(Console.ReadLine());
            Console.Write("Введите b: ");
            int b = int.Parse(Console.ReadLine());

            var temp = arr;
            temp = temp.OrderByDescending((x) => { return x >= a && x <= b; }).ToArray();
            arr = temp;

            Console.WriteLine("Преобразованный массив:");
            for (int i = 0; i < arr.Length; i++)
            {
                Console.Write(arr[i] + " ");
            }

            Console.ReadKey();
        }

        static void Task2()
        {
            int n = 10;

            Random random = new Random();

            // Формирование матрицы размером 10 х 10 и её вывод на консоль
            int[,] array = new int[n, n];

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    Console.Write("{0,3}", array[i, j] = random.Next(0, 10));
                }
                Console.WriteLine();
            }

            // Подсчет количества локальных минимумов
            Console.WriteLine("\nРасположение локальных минимумов [строка, столбец]:");

            int locMin = 0;
            for (int i = 1; i < n - 1; i++)
            {
                for (int j = 1; j < n - 1; j++)
                {
                    if (
                            (array[i, j] < array[i, j - 1]) &&
                            (array[i, j] < array[i - 1, j]) &&
                            (array[i, j] < array[i, j + 1]) &&
                            (array[i, j] < array[i + 1, j])
                        )
                    {
                        locMin++;
                        Console.WriteLine("[" + i + ", " + j + "] = " + array[i, j]);
                    }
                }
            }
            Console.WriteLine("\n\nКоличество локальных минимумов: " + locMin);

            // Поиск суммы модулей элементов, расположенных выше главной диагонали
            int sum = 0;
            for (int i = 0; i < n - 1; ++i)
            {
                for (int j = i + 1; j < n; ++j)
                {
                    sum += array[i, j];
                }
            }
            Console.WriteLine("\nСумма модулей элементов, расположенных выше главной диагонали: " + sum);

            Console.ReadKey();
        }

        static void Main(string[] args)
        {
            // Task1();
            // Task2();
        }
    }
}
