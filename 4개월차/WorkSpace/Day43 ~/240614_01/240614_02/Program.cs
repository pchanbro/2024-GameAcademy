namespace _240614_02
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello, World!");
            // 1) 변수 선언 + 사칙연산

            // 자료형 종류 (C#의 모든 자료형은 구조체로 이루어져 있다)
            // 기본 자료형 : int, float, bool, string(char대신에 보통 string를 쓴다)
            // 사용자 정의 자료형 : Enum, Struct, Class 등등

            int a = 0; // long 하면 8바이트(64비트)짜리 , int는 4바이트 짜리
            float b = 2.2f;
            bool c = true;
            string d = "aa";


            // C#의 변수특징
            // C#의 모든 자료형은 구조체로 이루어져 있는데 거기에는 대부분 ToString, GetType, GetHashCode, Equals가 존재한다.
            a.ToString();
            // object가 가장 베이스. (class) (나중에 한번 다시잡을게요)

            // object를 굳이 C++ 로 따진다면 => void*
            // object에 존재하는 함수 4개
            // GetType 어떤 자료형을 썼는지 반환, GetHashCode, ToString 문자열로 바꿔줌, Equals == 비교
            // 해당함수들은 어떤 자료형에나 다있습니다.

            Console.WriteLine(a.ToString());
            Console.WriteLine(a.GetType());
            Console.WriteLine(b.ToString());
            Console.WriteLine(c.ToString());
            Console.WriteLine(d.ToString());


            //ToString, GetType 정도만 기억하면됩니다.


            // 변수선언

            // C++에서는 auto => 컴파일 단계에서 자료형을 추정하여 사용하는 방법 
            // C++에서
            // auto a = 3;
            // 하면 a는 자동적으로 int형이 되는거

            // C#에서의 auto => var (variable)

            var aa = 3; // aa는 int형인걸 알 수 있다.

            // C++ 에서는 auto 를 웬만해서는 쓰지마라
            //  => 왜? : C++에는 포인터의 특성이 있기 때문
            //    그렇기때문에 우리가 주솟값을 넣는건지 아닌지, 주솟값의 주솟값을 넣는건지 애매할때가 많음
            //    그래서 간헐적으로 auto에 의해 오류나 버그가 일어날 가능성이 많다.

            // 하지만 C#에서는 안 쓸 이유가 없다 그러니까 쓰자
            var bb = 2.2f;
            Console.WriteLine(aa.ToString());
            Console.WriteLine(bb.ToString());

            var num1 = 10;
            var num2 = 20;
            Console.Write(num1);
            Console.Write(" + ");
            Console.Write(num2);
            Console.Write(" = ");
            Console.Write(num1 + num2);
            Console.Write("\n");

            // 위 과정을 한 줄로 바꾸기
            // 1. 올드한 문법
            Console.WriteLine(string.Format("{0} + {1} = {2}", num1, num2, num1 + num2)); // 순서는 0부터 차례대로 들어간다
            // 2. 최신 문법
            Console.WriteLine($"{num1} + {num2} = {num1 + num2}");

            // 사칙연산 C++ 와 모두 동일
            // ++, --, +=, -= , * / % - + 
        }
    }
}