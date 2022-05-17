using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SEM4_LR6
{
    internal class Card
    {
        private int _suit;
        private int _rank;
    }

    internal class Deck
    {
        private List<Card> _cards;

        public int Count
        {
            get => _cards.Count;
        }

        public Deck()
        {
            _cards = new List<Card>();
        }

        public Deck(int count)
        {
            _cards = new List<Card>(count);
        }

        public static Deck CreateStandard() 
        {
            const int Count = 54;

            Deck deck = new Deck(Count);

            // creating cards in loop ...

            return deck;
        }
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            Deck deck = Deck.CreateStandard();
        }
    }
}
