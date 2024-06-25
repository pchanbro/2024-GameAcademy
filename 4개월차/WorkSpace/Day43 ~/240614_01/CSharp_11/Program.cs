namespace CSharp_11
{
    internal class Program
    {
        //void AA()
        //{

        //} 이런거 만들어서 본문에서 호출하려해도 안됨

        static void Main(string[] args) // main은 static 공간이라서 static 함수만 호출 가능 그래서 객체를 만들어서 한거
        {
            App app = new App();
            app.Run();

            // AA(); 안됨
        }
    }
}