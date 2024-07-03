using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_11
{
    public class Student
    {
        public string Name;
    }


    internal class App
    {
        //ref 키워드는 할당된 객체를 수정하는 역할을 해주고
        public void CallByReference1(ref int value)
        {
            value++;
        }

        //out 키워드는 이 함수안에서 새롭게 할당해서 내보내겠다 라는 의미를 가집니다.
        public void CallByReference2(out Student value)
        {
            value = new Student();
            value.Name = "Dummy";
        }

        public int Run()
        {
            // 함수콜

            // C++ 에서는 뭔가 값을 변경하고싶다. 
            // 포인터로 보내거나 & 형태로 보내거나

            // C#에서는 포인터가 없기때문에 포인터로 보낼수가 없습니다.
            // &

            int a = 0;
            this.CallByReference1(ref a);

            Console.WriteLine($"A : {a}");

            Student student;
            this.CallByReference2(out student);

            Console.WriteLine($"student : {student.Name}");


            string line = Console.ReadLine();
            int result;
            if (int.TryParse(line, out result))
            {
                Console.WriteLine($"성공, 값 : {result}");
            }
            else
            {
                Console.WriteLine("변환 실패");
            }

            return 0;
        }
    }
}
