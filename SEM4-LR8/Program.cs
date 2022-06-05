using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using CityHousing;

namespace SEM4_LR8
{
    internal class Program
    {
        static void Main(string[] args)
        {
            City city = new City("Электросталь");

            Console.WriteLine("Город " + city.Name);

            Building building = new Building("Имени Данилы", 14, 7000, new List<Room>()
            {
                new Flat(10, 45, new List<string>() {"Иван Иванов" , "Марья Иванова"}),
                new Flat(33, 50, new List<string>() {"Семен Семнов", "Татьяна Семенова", "Гриша Семенов"}),
                new Office(42, 20, "Blizzard Entertainment"),
            });

            city.Buildings.Add(building);

            Console.WriteLine($"\nЗдания [{city.Buildings.Count} шт]:");

            foreach (Building build in city.Buildings)
            {
                Console.WriteLine('\n' + build.GenerateDescription());
                foreach (Room room in build.Rooms)
                {
                    Console.WriteLine($"- {room.GenerateDescription()} - Аренда плата {build.CalculateRoomRent(room.Number)} руб");
                }
            }

            Console.WriteLine("\n---------------\n");

            TaskSort(building);

            Console.WriteLine("\n---------------\n");

            TaskSearch(building);

            Console.ReadKey();
        }

        static void TaskSort(Building building)
        {
            Console.WriteLine("Отсортировать комнаты в здании. Выберите свойство:");
            Console.WriteLine("По номеру  - 1");
            Console.WriteLine("По площади - 2");
            Console.Write("\nВвод: ");
            int choice = int.Parse(Console.ReadLine());

            switch (choice)
            {
                case 1:
                    building.Rooms.Sort((x, y) => x.Number.CompareTo(y.Number));
                    break;
                case 2:
                    building.Rooms.Sort();
                    break;
                default:
                    Console.WriteLine("Неверный введенное значение...");
                    break;
            }

            Console.WriteLine("Сортировка комнат:\n");
            foreach (Room room in building.Rooms)
                Console.WriteLine(room.GenerateDescription());
        }

        static void TaskSearch(Building building)
        {
            Console.WriteLine("Поиск");
        }
    }
}
