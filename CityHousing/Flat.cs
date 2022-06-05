using System;
using System.Collections.Generic;

namespace CityHousing
{
    public class Flat : Room
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
            return "Квартира " + base.GenerateDescription() + $" - Кол-во жителей: {_tenantNames.Count}";
        }

        public override double GetRentCondition()
        {
            return (1 + (double)_tenantNames.Count * 0.1);
        }
    }
}
