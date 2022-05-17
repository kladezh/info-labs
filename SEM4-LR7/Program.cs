using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SEM4_LR7
{
    internal abstract class Room
    {
        private int _number;
        private int _area;

        public int Number
        {
            get => _number;
            set => _number = value;
        }
        public int Area
        {
            get => _area;
            set => _area = value;
        }

        public Room()
        {
        }
        public Room(int number, int area)
        {
            _number = number;
            _area = area;
        }

        virtual public string GenerateDescription()
        {
            return $"#{_number} - Площадь {_area} кв.м.";
        }

        abstract public double GetRentCondition();
    }

    internal class Flat : Room
    {
        private List<string> _tenantNames;

        public List<string> TenantNames
        {
            get => _tenantNames;
            set => _tenantNames = value;
        }

        public Flat() : base()
        {
            _tenantNames = new List<string>();
        }
        public Flat(int number, int area, List<string> tenantNames) : base(number, area)
        {
            _tenantNames = tenantNames;
        }

        public override string GenerateDescription()
        {
            return "Квартира " + base.GenerateDescription();
        }

        public override double GetRentCondition()
        {
            return (1 + (double)_tenantNames.Count * 0.1);
        } 
    }

    internal class Office : Room
    {
        private string _companyName;

        public string CompanyName
        {
            get => _companyName;
            set => _companyName = value;
        }

        public Office() : base()
        {
        }
        public Office(int number, int area, string companyName) : base(number, area)
        {
            _companyName = companyName;
        }

        public override double GetRentCondition()
        {
            return 2;
        }

        public override string GenerateDescription()
        {
            return "Офис " + base.GenerateDescription() + $" - Компания \"{_companyName}\"";
        }
    }

    internal class Building
    {
        private string _streetName;
        private int _index;
        private double _baseRent;

        private List<Room> _rooms;

        public string StreetName
        {
            get => _streetName;
            set => _streetName = value;
        }
        public int Index
        {
            get => _index;
            set => _index = value;
        }
        public double BaseRent
        {
            get => _baseRent;
            set => _baseRent = value;
        }

        public List<Room> Rooms
        {
            get => _rooms;
            set => _rooms = value;
        }

        public Building()
        {
            _rooms = new List<Room>();
        }
        public Building(string streetName, int index, double baseRent)
        {
            _streetName = streetName;
            _index = index;
            _baseRent = baseRent;

            _rooms = new List<Room>();
        }
        public Building(string streetName, int index, double baseRent, List<Room> rooms)
        {
            _streetName = streetName;
            _index = index;
            _baseRent = baseRent;

            _rooms = rooms;
        }

        public double CalculateRoomRent(int roomNumber)
        {
            Room room = _rooms.Find(x => x.Number == roomNumber);
            return _baseRent * Convert.ToDouble(room.Area) * room.GetRentCondition();
        }

        public int CalculateTotalArea()
        {
            int area = 0;
            foreach (Room room in _rooms)
                area += room.Area;

            return area;
        }

        public string GenerateDescription()
        {
            return $"Здание #{_index} - Улица {_streetName} - Помещений {_rooms.Count} - базовая стоимость аренды за кв.м {_baseRent} руб";
        }
    }

    internal class City
    {
        private string _name;

        private List<Building> _buildings;

        public string Name
        {
            get => _name;
            set => _name = value;
        }

        public List<Building> Buildings
        {
            get => _buildings;
            set => _buildings = value;
        }

        public City()
        {
            _buildings = new List<Building>();
        }
        public City(string name)
        {
            _name = name;

            _buildings = new List<Building>();
        }
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            City city = new City("Электросталь");

            city.Buildings = new List<Building>()
            {
                new Building("Имени Данилы", 14, 7000, new List<Room>()
                {
                    new Flat(10, 45, new List<string>() {"Иван Иванов, Марья Иванова"}),
                    new Flat(33, 50, new List<string>() {"Семен Семнов, Татьяна Семенова, Гриша Семенов"}),
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
