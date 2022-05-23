using System;

namespace CityHousing
{
    public class Office : Room
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
}
