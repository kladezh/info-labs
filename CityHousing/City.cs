using System;
using System.Collections.Generic;

namespace CityHousing
{
    public class City
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
}
