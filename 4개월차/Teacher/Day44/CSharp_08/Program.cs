namespace CSharp_08
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //랜덤
            Random random = new Random();
            //C++에서는
            //srand(time(NULL)) 을썻지만, C#은 안써도 된다.

            for (int i = 0; i < 100; i++)
            {
                int a = random.Next(0, 10);
                Console.WriteLine($"random : {a}");
            }
        }
    }
}


//Comment:
// C++ 이랑 다른게 크게없어서
// 굳이 복습용으로 숙제는 안낼거에요.

// 그런데 꼭 복습을 해보고 싶다.


// 기본적으로
// C++때 만들었던 콘솔숙제들
// 똑같이만드시면, 숙련도는 많이 올라갑니다.

// 숫자야구
// 빙고게임
// 