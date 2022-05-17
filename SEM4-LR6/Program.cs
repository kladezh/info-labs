using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SEM4_LR6
{
    internal enum Suit
    {
        Hearts,
        Diamons,
        Clubs,
        Spades
    }
    internal enum Rank
    {
        Ace = 11,
        King = 10,
        Queen = 10,
        Jack = 10,
        Ten = 10,
        Nine = 9,
        Eight = 8,
        Seven = 7,
        Six = 6,
        Five = 5,
        Four = 4,
        Three = 3,
        Two = 2
    }

    internal class Card
    {
        private Suit _suit;
        private Rank _rank;

        public Suit Suit
        {
            get => _suit;
            set => _suit = value;
        }

        public Rank Rank
        {
            get => _rank;
            set => _rank = value;
        }

        public Card(Suit suit, Rank rank)
        {
            _suit = suit;
            _rank = rank;
        }
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
