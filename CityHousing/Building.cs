using System;
using System.Collections.Generic;

namespace CityHousing
{
    public class Building : IComparable<Building>
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

        public int CompareTo(Building other)
        {
            if(other is null)
                return 1;

            return this.CalculateTotalArea().CompareTo(other.CalculateTotalArea());
        }
    }
}
