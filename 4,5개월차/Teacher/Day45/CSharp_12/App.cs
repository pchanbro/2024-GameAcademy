using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_12
{
    public class Student()
    {

    }

    public enum MyEnum
    {
        A = 1,
        B = 2
    }


    internal class App
    {
        public void Run()
        {
            // 메모리 구조
            GC.Collect(); // 가비지컬렉터 요청. 100%되진않음.

            int a = 0; // struct System.Int32
            float b = 0.0f; // struct System.Single


            // C# 변수 특징
            // 1. 모든 변수는 Struct or Class 다.
            // 2. 모든 변수는 object로 변환이 가능하다.
            //   - 그렇기 때문에 ToString과 GetType 함수를 모든 변수에서 사용가능하다.


            //boxing unboxing
            //주로할수있는 실수들에 대해서 볼게요
            //1. 가장 쉬운 실수
            List<object> list = new List<object>();

            list.Add(0); // boxing
            list.Add(new Student());
            list.Add(5); // boxing


            foreach (object o in list)  // 요소가 10000개면, 10000개의 unboxing이 일어납니다.
            {
                if(o is Student)
                {
                    Student student = (Student)o;
                }
                else if (o is int)
                {
                    int value = (int)o; // object => int  (unboxing)

                }
            }

            // Unity Programming
            //Debug.Log

            for (int i = 0; i < 1000; i++)
            {
                Debug.Log(0);   //struct => class (boxing)
            }

            //object 자료형으로 기교를 진짜많이부리는데, 
            // 그떄마다 boxing, unboxing 꼭 조심해야합니다.


            //2. enum ( C# 특정버전 이후부터는 고쳐진거로아는데, 아마 Unity는 안고쳐진거로 알고있습니다.)
            MyEnum a = MyEnum.A;
            MyEnum b = MyEnum.B;

            // boxing 발생합니다.
            // 옛날에 무슨무슨 컨퍼런스에 발표해가지고
            if(a.Equals(b))
            {

            }



            // 면접용으로 외울 내용 한줄요약!
            // 1. unboxing은 힙에 쓰레기가 남는다. 그래서 GC때문에 좋지 않다. 안쓰는게 좋다.
            // 2. boxing도 느리다. 지양하는게 좋다.
            //  (10배?)

            // boxing, unboxing 코딩습관은 되게 중요해요.

        }
    }

    public class Debug
    {
        public static void Log(object message)
        {
            Console.WriteLine(message);
        }
    }

}
