namespace _240614_03
{
    internal class Program // internal 굳이 public 안바꿔도 되긴함
    {
        static void Main(string[] args)
        {
            // 2) if문, for문, while문, switch문

            var input = Console.ReadLine();

            Console.WriteLine($"Input : {input}");

            // C++에선 const char* -> strcmp를 통해서 비교했는데 
            // C#에선 그냥 == 으로 비교하자
            if( input == "1")
            {
                Console.WriteLine("1");
            }
            else if(input == "2")
            {
                Console.WriteLine("2");
            }

            // 그리고 또 C++에서는
            // int a = 1;
            // if(a) -> 이런식으로 a만 조건문에 넣어줘도 되는데 C#에서는 이게 오류가 된다. 무조건 비교연산자( <, >, ==, !=)을 써서 bool값을 넣어줘야함
            // 물론 bool 값인 true나 false는 가능하다.
            // if문 조건 뿐만 아니라, for, while, switch 모두 그렇다.
            // {
            //      Console.WriteLine("들어온다"); 
            // }


            //for문
            //for(int i = 0; i< 10; i++)
            //{
            //    for(int j = 0; j < 10; j++)
            //    {
            //        Console.WriteLine("*");
            //    }
            //    Console.WriteLine();
            //}

            //for문 별찍기
            //Input

            //input => int 
            // 사이즈5인지
            // 사이즈가 10인지


            // 1.계산기 (+ - * / )
            Console.Write("첫번째 숫자 :");
            var inputNum1 = Console.ReadLine();
            int num1 = int.Parse(inputNum1);

            Console.Write("두번째 숫자 :");
            var inputNum2 = Console.ReadLine();
            int num2 = int.Parse(inputNum2);

            Console.Write("계산방식을 선택하세요 (1 : 더하기, 2 : 빼기, 3 : 나누기, 4 : 나머지) : ");
            var inputNum3 = Console.ReadLine();
            int choice = int.Parse(inputNum3);

            if(choice == 1)
            {
                Console.WriteLine($"{num1} + {num2} = {num1 + num2}");
            }
            else if (choice == 2)
            {
                Console.WriteLine($"{num1} - {num2} = {num1 - num2}");
            }
            else if (choice == 3)
            {
                Console.WriteLine($"{num1} / {num2} = {num1 / num2}");
            }
            else if (choice == 4)
            {
                Console.WriteLine($"{num1} % {num2} = {num1 % num2}");
            }

            // 풍차돌리기
            // 사이즈 5 풍차돌리기

            // *****    *
            //  ****   **
            //   ***  ***
            //    ** ****
            //     ******
            // ******
            // **** **
            // ***  ***
            // **   ****
            // *    *****

            // 2.별찍기 (풍차돌리기)
            // input을 int로 바꾸는 방법

            Console.WriteLine("풍차 별 갯수를 선택하세요 : ");
            var inputString = Console.ReadLine();
            int size = int.Parse(inputString);
            Console.WriteLine(size);

            for(int i = 0; i < size; i++)
            {
                for(int j = 0; j < i; j++)
                {
                    Console.Write(" ");
                }
                for(int j = 0; j < size - i; j++)
                {
                    Console.Write("*");
                }
                for(int j = 0; j < size-(i+1); j++)
                {
                    Console.Write(" ");
                }
                for (int j = 0; j < i + 1; j++)
                {
                    Console.Write("*");
                }
                Console.WriteLine();
            }

            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size- i; j++)
                {
                    Console.Write("*");
                }
                for (int j = 0; j < i; j++)
                {
                    Console.Write(" ");
                }
                for (int j = 0; j < i + 1; j++)
                {
                    Console.Write("*");
                }
                for (int j = 0; j < size - (i + 1); j++)
                {
                    Console.Write(" ");
                }
                Console.WriteLine();
            }
        }
    }
}