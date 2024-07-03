namespace _20240614_03
{
    internal class Program
    {
        static void Main(string[] args)
        {
            // 2) if문, for문, while문, switch문


            //for문 별찍기
            //Input

            //input => int 
            // 사이즈5인지
            // 사이즈가 10인지

            // 풍차돌리기
            // 사이즈 5 풍차돌리기

            // *****    *
            //  ****   **
            //   ***  **ㅑ
            //    ** ****
            //     ******
            // ******
            // **** **
            // ***  ***
            // **   ****
            // *    *****

            var inputString = Console.ReadLine();
            int size =  int.Parse(inputString);
            Console.WriteLine(size);

            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    Console.Write("*");
                }
                Console.WriteLine();
            }

            // 1.계산기 (+ - * / )
            // 2.별찍기 (풍차돌리기)

            // 9시 10분까지 
        }
    }
}
