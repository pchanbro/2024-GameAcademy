namespace _20240614_07
{
    public enum RockScissorPaper
    {
        Rock,
        Scissor,
        Paper,
    }

    public class Program
    {
        static void Main(string[] args)
        {
            RockScissorPaper rockScissorPaper = RockScissorPaper.Paper;

            // :: => .
            // -> => .
            // .  => .

            //GetType, ToString
            Console.WriteLine($"rockScissorPaper : {rockScissorPaper.ToString()}");

            Console.WriteLine("Hello, World!");
        }
    }
}

// Enum문 

//접근 제어자 4개
// internal, private, protected, public
// internal : 해당 프로젝트에서 모두 사용가능.
// private : 자기 자신만 사용가능
// protected : 나를 상속받은 애만 사용가능
// public : 누구나 사용가능.