namespace _240614_05
{
    internal class Program
    {
        static void Main(string[] args)
        {
            var inputString = Console.ReadLine();
            int size = int.Parse(inputString ?? "0");
            Console.WriteLine(size);


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

            for (int y = 0; y < size; y++)
            {
                for (int x = 0; x < size; x++)
                {
                    if (y <= x)
                    {
                        Console.Write("*");
                    }
                    else
                    {
                        Console.Write(" ");
                    }
                }
                for (int x = 0; x < size; x++)
                {
                    if (size - x - 1 <= y)
                    {
                        Console.Write("*");
                    }
                    else
                    {
                        Console.Write(" ");
                    }
                }
                Console.WriteLine();
            }

            for (int y = 0; y < size; y++)
            {
                for (int x = 0; x < size; x++)
                {
                    if (size - y - 1 >= x)
                    {
                        Console.Write("*");
                    }
                    else
                    {
                        Console.Write(" ");
                    }
                }
                for (int x = 0; x < size; x++)
                {
                    if (x <= y)
                    {
                        Console.Write("*");
                    }
                    else
                    {
                        Console.Write(" ");
                    }
                }
                Console.WriteLine();
            }

        }
    }
}
