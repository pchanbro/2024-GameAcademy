// Enum문 

//접근 제어자 4개
// internal, private, protected, public
// internal : 해당 프로젝트에서 모두 사용가능.
// private : 자기 자신만 사용가능
// protected : 나를 상속받은 애만 사용가능
// public : 누구나 사용가능.

namespace _240614_06
{
    public enum RockScissorPaper : int // : int 이렇게 해준건 최대 범위를 지정해준 것
    { 
        Rock = 100,
        Scissor,
        Paper,
    }

    public class Program
    {
        static void Main(string[] args)
        {
            // C#에서 사용자 정의를 선언하려면 전부 new로 해야함
            RockScissorPaper rockScissorPaper = RockScissorPaper.Paper;

            // C++에서는 ::, ->, . 쓰던거
            // C#에서는 전부 . 으로 한다.

            // GetType, ToString
            Console.WriteLine($"rockScissorPaper : {rockScissorPaper.ToString()}");
            // enum을 ToString 하면 위에 enum에서 넣어준 이름인 Rock, Scissor 이런 것들이 나온다

            Console.WriteLine("Hello, World!");
        }
    }
}


// C++ Tower Defense 만들기 숙제 - 한달 짜리, 꼭 