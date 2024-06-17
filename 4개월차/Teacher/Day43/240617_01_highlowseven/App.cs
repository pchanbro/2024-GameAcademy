using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _240617_01_highlowseven
{
    internal class App
    {
        private List<int> _cards = new List<int>();
        private int _cardNum = 0;

        public void Run()
        {
            for(int i = 0; i < 52; i++)
            {
                _cards.Add(i);
            }

            Random rand = new Random();

            // 이 셔플 부분때문에 문제가 일어남
            for (int i = 0; i < 100000; i++)
            {
                int rand1 = rand.Next(1, 52);
                int rand2 = rand.Next(1, 52);
                int temp = _cards[rand1];
                _cards[rand1] = _cards[rand2];
                _cards[rand2] = temp;
            }

            //기본자료형
            int myValue = 10;
            float myValue1 = 10.0f;
            bool myValue2 = true;
            string myValue3 = "string";
            object myValue4 = null;

            Console.WriteLine(myValue);
            Console.WriteLine($"myValue : {myValue}");
            string myLine = Console.ReadLine();

            Console.WriteLine($"myLine : {myLine}");

            //문자열 => int
            //int value = int.Parse(myLine == null? "0" :  myLine );
            int value = int.Parse(myLine ?? "0");
            Console.WriteLine($"value : {value}");

            foreach(int i in _cards)
            {
                PrintCard(i);
                Console.WriteLine();
            } //이거 하면 모든 요소를 한번씩 돌면서 보여줌

            while ( _cardNum < 48)
            {
                for(int i = 0; i < 4; i++)
                {
                    PrintCard(_cardNum + i);
                }
                Console.Write("xx");
                Console.WriteLine();

                Console.Write("하이로우 세븐을 입력하세요 (0 : High, 1 : Low, 2 L Seven) : ");
                string highLowSeven = Console.ReadLine();
                int choice = int.Parse(highLowSeven ?? "0");

                switch (choice)
                {
                    case 0:
                        Console.WriteLine("플레이어의 선택 : High");
                        
                        break;
                    case 1:
                        Console.WriteLine("플레이어의 선택 : Low");
                        break; 
                    case 2:
                        Console.WriteLine("플레이어의 선택 : Seven");
                        break;
                }
                _cardNum++;
                Console.WriteLine($"{_cardNum}");
            }
        }

        public void PrintCard(int cardNum)
        {
            switch (_cards[cardNum] / 13)
            {
                case 0:
                    Console.Write($"♠");
                    break;
                case 1:
                    Console.Write($"♡");
                    break;
                case 2:
                    Console.Write($"♠");
                    break;
                case 3:
                    Console.Write($"☆");
                    break;
            }

            switch(_cards[cardNum] % 13)
            {
                case 0:
                    Console.Write("A");
                    break;
                case 10:
                    Console.Write("J");
                    break;
                case 11:
                    Console.Write("Q");
                    break;
                case 12:
                    Console.Write("K");
                    break;
                default:
                    Console.Write($"{cardNum % 13}");
                    break;
            }

            Console.Write(" ");
        }
    }
}
