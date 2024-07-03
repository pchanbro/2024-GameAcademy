namespace _240614_04
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //계산기

            //Console.WriteLine("")

            while (true)
            {
                Console.WriteLine("수식(+-*%/) or (quit)을 입력하세요.");
                var input = Console.ReadLine();

                if (input == "quit")
                {
                    break;
                }

                Console.WriteLine("첫번째 숫자를 입력해주세요.");
                var num1String = Console.ReadLine();
                Console.WriteLine("두번째 숫자를 입력해주세요.");
                var num2String = Console.ReadLine();

                var num1 = int.Parse(num1String ?? "0");
                // 이렇게 ?? 해주는건 아래 2가지 경우와 같다
                // 1번
                //var num1 = int.Parse((num1String != null) ? num1String :  "0"); 
                // 2번
                //if(num1String != null)
                //{
                //    var num1 = int.Parse(num1String);
                //} 
                var num2 = int.Parse(num2String ?? "0");

                switch (input)
                {
                    case "+":
                        Console.WriteLine($"{num1} + {num2} = {num1 + num2}");
                        break;
                    case "-":
                        Console.WriteLine($"{num1} - {num2} = {num1 - num2}");
                        break;
                    case "*":
                        Console.WriteLine($"{num1} * {num2} = {num1 * num2}");
                        break;
                    case "%":
                        Console.WriteLine($"{num1} % {num2} = {num1 % num2}");
                        break;
                    case "/":
                        Console.WriteLine($"{num1} / {num2} = {num1 / num2}");
                        break;
                }

            }
        }
    }
}