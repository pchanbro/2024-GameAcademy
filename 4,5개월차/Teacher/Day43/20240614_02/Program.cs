namespace _20240614_02
{
    internal class Program
    {
        static void Main(string[] args)
        {
            // 1) 변수 선언 + 사칙연산

            // 자료형 종류
            // 기본 자료형 : int, float, bool, string
            // 사용자 정의 자료형 : Enum, Struct, Class 등등

            int a = 0;
            float b = 2.2f;
            bool c = true;
            string d = "aa";

            // C#의 변수특징
            // object가 가장 베이스. (class) (나중에 한번 다시잡을게요)

            // 굳이 C++ 로 따진다면 (void*)
            // object에 존재하는 함수 4개
            // GetType, GetHashCode, ToString, Equals
            // 해당함수들은 어떤 자료형에나 다있습니다.

            Console.WriteLine(a.ToString());
            Console.WriteLine(a.GetType());
            Console.WriteLine(b.ToString());
            Console.WriteLine(c.ToString());
            Console.WriteLine(d.ToString());


            //ToString, GetType 정도만 기억하면됩니다.


            // 변수선언

            // C++에서는 auto => 컴파일 단계에서 자료형을 추정하여 사용하는 방법
            // C#에서도 auto => var (variable)

            var aa = 3;

            // C++ 에서는 auto 를 웬만해서는 쓰지마라라
            //  => 왜? : C++에는 포인터의 특성
            //    그렇기때문에 우리가 주솟값을 넣는건지 아닌지, 주솟값의 주솟값을 넣는건지 애매할때가 많음

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

            Console.WriteLine(string.Format("{0} + {1} = {2}", num1, num2, num1 + num2));

            Console.WriteLine($"{num1} + {num2} = {num1 + num2}");


            // 사칙연산 C++ 와 모두 동일
            // ++, --, +=, -= , * / % - + 
        }
    }
}
