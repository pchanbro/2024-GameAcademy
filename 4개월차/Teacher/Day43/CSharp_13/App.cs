using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_13
{
    public class MyClass
    {
        private int _number;

        // Only 프로퍼티
        public int Number
        {
            get
            {
                return _number;
            }
            set
            {
                _number = value;
            }
        }

        // 변수이면서 프로퍼티
        public int Money { get; private set; } = 20; // 이 경우엔 get은 어디서든 가능, set은 내꺼에서만 가능
        // 그리고 선언과 동시에 초기화


        public override string ToString()
        {
            return $"_number : {Number}";
        }
    }

    internal class App
    {
        public void Run()
        {
            // 클래스, 웬만하면 C++이랑 비슷한데 property는 다르다.
            //  - property
            //  - 변수초기화(선언과 동시에 초기화 가능)
            //  - 상속


            // 우리가 변수를 만들면
            // 대부분 getter, setter 를 (필요시) 만들어줬다.

            MyClass myClass = new MyClass();
            myClass.Number = 3;
            // myClass.Money = 3; private로 막아놔서 불가

            Console.WriteLine(myClass.Money);
            Console.WriteLine(myClass.ToString);


            // 클래스 상속 and 인터페이스

            // 상속 << 공통된 부모의 기능을 같이 쓰기위해서 아키텍처를 만드는 것
            // Ex) Actor => SpriterActor => MoleActor
            // Ex) Actor => FlipbookActor => CreaterActor 등 만들었었다.

            // Actor를 부모 class 로 하는 이유는 
            // Actor들을 한 번에 관리하기 위해서, (씬에서 vector<Actor*> 로 들고 컨트롤하기 위해서)

            // SpriteActor
            //  => 스프라이트를 출력하는 함수기능을 같이 쓰기위해서

            // C#에서는 기능을 같이쓰기 위해서 상속받는건지, 관리를 위해 상속받는건지에 따라
            // 인터페이스가 더 효율적일때가 있다.

            // 인터페이스

        }
    }

    // 인터페이스는 '함수만' '선언만' 가능하다
    // 정의는 불가능
    public interface IAttacker // 인터페이스 이름은 무조건 I로 시작한다.
    {
        void Attack();

        public float Damage { get; set; }
    }


    public class Hero : IAttacker
    {
        public string Name = "Dummy";
        public float Hp = 100.0f;

        public float Damage { get; set; } = 30;

        void IAttacker.Attack() // 인터페이스를 상속받으면 상속받은 인터페이스에 있는 함수를 정의해야함
        {

        }
    }
 
}
