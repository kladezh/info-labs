using System;

namespace CityHousing
{
    public abstract class Room
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
}
