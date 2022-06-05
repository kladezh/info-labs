using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using CityHousing;

namespace SEM4_LR7
{
    internal class Program
    {
        static void Main(string[] args)
        {
            City city = new City("Электросталь");

            city.Buildings = new List<Building>()
            {
                new Building("Имени Данилы", 14, 7000, new List<Room>()
                {
                    new Flat(10, 45, new List<string>() {"Иван Иванов" , "Марья Иванова"}),
                    new Flat(33, 50, new List<string>() {"Семен Семнов", "Татьяна Семенова", "Гриша Семенов"}),
                    new Office(42, 20, "Blizzard Entertainment"),
                }),
                new Building("Имени Кашина", 7, 10000, new List<Room>()
                {
                    new Office(33, 12, "Take-Two Interactive"),
                }),
            };


            Console.WriteLine("Город " + city.Name);

            Console.WriteLine($"\nЗдания [{city.Buildings.Count} шт]:");
            foreach (Building building in city.Buildings)
            {
                Console.WriteLine('\n' + building.GenerateDescription());
                foreach (Room room in building.Rooms)
                {
                    Console.WriteLine($"- {room.GenerateDescription()} - Аренда плата {building.CalculateRoomRent(room.Number)} руб");
                }
            }

            Console.ReadKey();
        }
    }
}
