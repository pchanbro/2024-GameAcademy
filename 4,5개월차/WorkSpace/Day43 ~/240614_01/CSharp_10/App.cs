using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

// C# 하이로우세븐 선생님 풀이 

namespace CSharp_10
{
    public class App
    {
        //C++에서는 
        // 접근제어자:
        //    그아래에 함수를 선언

        //C#에서는 모든 함수, 모든변수에
        // 접근 제어를 직접 써줘야해요.

        // C# 클래스 변수선언 특별한점.
        // 클래스 변수선언과 동시에 동적할당이 가능.
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
            Random random = new Random();
            for (int i = 0; i < 10000; i++)
            {
                int rand1 = random.Next(0, 51);
                int rand2 = random.Next(0, 51);
                int temp = _cards[rand1];
                _cards[rand1] = _cards[rand2];
                _cards[rand2] = temp;
            }


            int cardIndex = 0;
            int money = 1000;

            while (cardIndex < _cards.Count - 5 && 0 < money)
            {
                for (int i = 0; i < 4; i++)
                {
                    PrintCard(_cards[cardIndex + i]);
                    Console.WriteLine();
                }
                Console.WriteLine("XX");

                Console.WriteLine($"배팅을 얼마하시겠습니까? (소지금 : {money})");

                string betMoneyString = Console.ReadLine();
                int betMoney = int.Parse(betMoneyString ?? "0");

                if (betMoney == 0)
                {
                    Console.WriteLine("베팅을 하지않아, 다음판으로 넘어갑니다.");
                    cardIndex++;
                    continue;
                }

                money -= betMoney;

                Console.WriteLine($"하이(0) 로우(1) 세븐(2) 중에 골라주세요.");
                string betChoiceString = Console.ReadLine();
                int betChoice = int.Parse(betChoiceString ?? "-1");

                while (betChoice == -1)
                {
                    Console.WriteLine($"다시 하이(0) 로우(1) 세븐(2) 중에 골라주세요.");
                    betChoiceString = Console.ReadLine();
                    betChoice = int.Parse(betChoiceString ?? "-1");
                }

                int currentCardNumber = _cards[cardIndex + 4] % 13 + 1;

                Console.Write("XX의 정체 : ");
                PrintCard(_cards[cardIndex + 4]);
                Console.WriteLine();

                if (betChoice == 0 && 7 < currentCardNumber)
                {
                    Console.WriteLine($"승리했습니다.");
                    money += betMoney * 2;
                }

                if (betChoice == 1 && currentCardNumber < 7)
                {
                    Console.WriteLine($"승리했습니다.");
                    money += betMoney * 2;
                }

                if (betChoice == 2 && currentCardNumber == 7)
                {
                    Console.WriteLine($"세븐으로 승리했습니다.");
                    money += betMoney * 10;
                }

                cardIndex++;
            }



        }


        void PrintCard(int card)
        {
            switch (card / 13)
            {
                case 0:
                    Console.Write("♤");
                    break;
                case 1:
                    Console.Write("◆");
                    break;
                case 2:
                    Console.Write("♥");
                    break;
                case 3:
                    Console.Write("♧");
                    break;
            }

            switch (card % 13 + 1)
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
                    Console.Write(card % 13 + 1);
                    break;
            }


        }
    }
}
