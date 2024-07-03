using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_09
{
    internal class App
    {
        //C++에서는 
        // 접근제어자:
        //    그아래에 함수를 선언

        //C#에서는 모든 함수, 모든변수에
        // 접근 제어를 직접 써줘야해요.

        // C# 클래스 변수선언 특별한점.
        // 클래스 변수선언과 동시에 동적할당이 가능.(이거 C++에서는 동적할당이 불가능해 nullptr 넣어줬음)
        private List<int> _cards = new List<int>();

        public void Run()
        {
            //간단하게 하이로우세븐 C#버전으로 만들어보겠습니다.

            // 화면에 5개 카드 나오고
            // XX ◇7 ◇5 ♣5 ♡4

            // XX의 크기가 7인지, 7보다큰지, 7보다작은지 베팅
            // 플레이어의 돈이 다떨어지면 패배
            // 52장 다쓰면 52장 다시 리필 (혹은 게임끝)

            // 20분까지 진행!

            // C++ 했던거에서 수도코드는 안바뀝니다.

            for (int i = 0; i < 52; i++)
            {
                _cards.Add(i);
            }

            Random rand = new Random();

            // 이 셔플 부분때문에 문제가 일어남
            for (int i = 0; i < 100000; i++)
            {
                int rand1 = rand.Next(0, 51);
                int rand2 = rand.Next(0, 51);
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

            foreach (int i in _cards)
            {
                PrintCard(i);
                Console.WriteLine();
            } //이거 하면 모든 요소를 한번씩 돌면서 보여줌

            int _cardNum = 0;

            while (_cardNum < 48)
            {
                for (int i = 0; i < 4; i++)
                {
                    PrintCard(_cards[_cardNum + i]);
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

        public void PrintCard(int card)
        {
            switch (_cards[card] / 13)
            {
                case 0:
                    Console.Write($"♤");
                    break;
                case 1:
                    Console.Write($"◆");
                    break;
                case 2:
                    Console.Write($"♧");
                    break;
                case 3:
                    Console.Write($"♥");
                    break;
            }

            switch (_cards[card] % 13 + 1)
            {
                case 1:
                    Console.Write("A");
                    break;
                case 11:
                    Console.Write("J");
                    break;
                case 12:
                    Console.Write("Q");
                    break;
                case 13:
                    Console.Write("K");
                    break;
                default:
                    Console.Write($"{card % 13 + 1}");
                    break;
            }

            Console.Write(" ");
        }
    }
}
