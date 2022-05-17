using System;
using System.Collections.Generic;
using System.Security.Cryptography;
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
        Two = 2,
        Three = 3,
        Four = 4,
        Five = 5,
        Six = 6,
        Seven = 7,
        Eight = 8,
        Nine = 9,
        Ten = 10,
        Jack,
        Queen,
        King,
        Ace,
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

        public override string ToString()
        {
            return string.Concat(_suit.ToString(), ' ', _rank.ToString());
        }
    }

    internal class Deck
    {
        private const int _StandardCount = 52;

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

        public void Add(Card card)
        {
            _cards.Add(card);
        }

        public Card Take()
        {
            int index = _cards.Count - 1;

            Card top = _cards[index];

            _cards.RemoveAt(index);

            return top;
        }

        public List<Card> Take(int count)
        {
            int index = this.Count - count;

            List<Card> top = _cards.GetRange(index, count);

            _cards.RemoveRange(index, count);

            return top;
        }

        public static Deck CreateStandard()
        {
            Deck deck = new Deck(_StandardCount);

            foreach (Suit suit in Enum.GetValues(typeof(Suit)))
            {
                foreach (Rank rank in Enum.GetValues(typeof(Rank)))
                {
                    deck.Add(new Card(suit, rank));
                }
            }

            return deck;
        }

        public void Shuffle()
        {
            _cards.Shuffle();
        }

        public override string ToString()
        {
            string result = "";
            foreach(Card card in _cards)
                result += string.Concat(card.ToString(), '\n');
            
            return result;
        }
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            Deck deck = Deck.CreateStandard();

            Console.WriteLine($"Сгенерированная колода карт [{deck.Count} шт]:");
            Console.WriteLine(deck.ToString());

            deck.Shuffle();

            Console.WriteLine($"Перетасованная колода карт [{deck.Count} шт]:");
            Console.WriteLine(deck.ToString());

            Console.WriteLine("\nВзять карту...\n");

            Card topCard = deck.Take();

            Console.WriteLine("Карта:");
            Console.WriteLine(topCard.ToString());

            Console.WriteLine("\nВзять 6 карт...\n");

            List<Card> takedCards = deck.Take(6);

            Console.WriteLine("Карты:");
            foreach (Card card in takedCards)
                Console.WriteLine(card.ToString());

            Console.WriteLine($"\nКол-во карт в колоде [{deck.Count} шт]");

            Console.ReadKey();
        }
    }

    internal static class ListExtension
    {
        public static void Shuffle<T>(this IList<T> list)
        {
            /* List shuffle algorithm: 
             * 
             * https://stackoverflow.com/questions/273313/randomize-a-listt
             * 
             */

            RNGCryptoServiceProvider provider = new RNGCryptoServiceProvider();
            int n = list.Count;
            while (n > 1)
            {
                byte[] box = new byte[1];
                do provider.GetBytes(box);
                while (!(box[0] < n * (Byte.MaxValue / n)));
                int k = (box[0] % n);
                n--;
                T value = list[k];
                list[k] = list[n];
                list[n] = value;
            }
        }
    }
}
