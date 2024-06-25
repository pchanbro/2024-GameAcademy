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

            object o = a;  // boxing, object는 class
            int c = (int)o; // unboxing 
                            // 여기서 stack 영역에 int(o)라는걸 만들고 heap 영역에 또다른 클래스를 만들어
                            // o를 복제한다, 이 때 int(o)가 heap영역에 그 클래스를 가리키고 이후 그 값을 c에다 넣어준다.
                            // 그러고 나면 int(o)는 사라지는데 그렇게 되면 heap 영역에 o를 복제한(참조가 끊긴)게 남게 됨
                            // 그럼 이걸 언젠가 delete 하는 일이 일어나게 된다.(최적화에 치명적인 상황이 생긴다)

            // c# 변수 특징
            // 1. 모든 변수는 Struct or Class 다
            // 2. 모든 변수는 object로 변환이 자식이다.(사실 자식은 아닌데 자식이라 생각해도 된다.)
            //   - 그렇기 때문에 ToString과 GetType 함수를 모든 변수에서 사용가능하다.


            // boxing unboxing
            // Array는 boxing unboxing 덩어리니까 그냥 절대 쓰지말기

            // 주로할 수 있는 실수들에 대해서

            //1. 가장 쉬운 실수
            List<object> list = new List<object>();

            list.Add(0); // boxing
            list.Add(new Student());
            list.Add(5); // boxing


            foreach (object o in list)  // 요소가 10000개면, 10000개의 unboxing이 일어난다. 즉 이 코드를 실행하면 엄청난 일이 일어난다.
            {
                if (o is Student)
                {
                    Student student = (Student)o;
                }
                else if (o is int)
                {
                    int value = (int)o; // object => int  (unboxing)

                }
            }

            // Unity Programming 을 하다보면
            // Debug.Log를 많이 한다.

            for (int i = 0; i < 1000; i++)
            {
                Debug.Log(0);   // struct => class (boxing)  parameter가 object면 꼭 클래스로 넘겨라
                // 이거는 개발에만 쓰이는거라 사실 안고쳐도 상관이 없다.
            }

            // object가 편리하다 보니 object 자료형으로 기교를 매우 많이 부리는데,
            // 그럴 때 마다 boxing, unboxing을 꼭 조심해야한다.


            // 2. enum (C# 특정 버전 이후부터는 고쳐진것 같은데, 아마 unity에서는 안고쳐진것 같음)
            MyEnum a = MyEnum.A;
            MyEnum b = MyEnum.B;

            // boxing 발생함
            // 옛날에 아무도 모르다가 무슨 컨퍼런스에 발표해서 
            if (a.Equals(b)) // 그래서 Equals 쓰지 마셈 문제 발생
            {

            }

            if (a == b) // == 을 써라
            {

            }

            // 면접용으로 외울 내용 한줄요약
            // 1. unboxing은 힙에 쓰레기가 남는다. 그래서 GC때문에 좋지 않다. 안쓰는게 좋다.
            // 2. boxing도 느리다. 최대한 지양하는게 좋다
            //  (10배정도 unboxing이 boxing보다 더 느리다)

            // 면접용으로는 이정도지만 코딩 할 때는 상당히 조심해야한다.

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
