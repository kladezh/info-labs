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

        abstract public double RentCondition();
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

        public override double RentCondition()
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

        public override double RentCondition()
        {
            return 2;
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

        public int TotalArea()
        {
            int area = 0;
            foreach (Room room in _rooms)
                area += room.Area;

            return area;
        }

        public double TotalRent()
        {
            double rent = 0.0;
            foreach (Room room in _rooms)
                rent += _baseRent * Convert.ToDouble(room.Area) * room.RentCondition();

            return rent;
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
        }
    }
}
