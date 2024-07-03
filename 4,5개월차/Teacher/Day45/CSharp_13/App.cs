using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_13
{
    public class MyClass
    {
        private int _number = 100;

        //Only 프로퍼티
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

        //변수이면서 프로퍼티
        public int Money { get; private set; } = 20;


        public override string? ToString()
        {
            return $"_number : {_number}";
        }
    }

    internal class App
    {
        public void Run()
        {
            // 클래스 
            //  - Property
            //  - 변수초기화
            //  - 상속


            // 변수를 만들면
            // getter, setter 를 (필요시) 만들어줬습니다.

            MyClass myClass = new MyClass();

            Console.WriteLine(myClass.Money);
            Console.WriteLine(myClass.ToString());


            //클래스 상속 and 인터페이스.

            // 상속 << 공통된 부모의 기능을 같이 쓰기위해서 아키텍처를 만드는거.. 
            // Actor => SpriteActor => MoleActor
            // Actor => FlipbookActor => CreatureActor

            // Actor를 부모 class로 이유는 
            // Actor들을 한번에 관리하기위해서, (씬에서 vector<Actor*> 로 들고 컨트롤하기 위해서)

            // SpriteActor 
            //  => 스프라이트를 출력하는 함수기능을 같이 쓰기위해서,

            // C#에서는 기능을 같이쓰기위해서 상속을받는건지, 관리를 위해서 상속을받는건지에 따라
            // 인터페이스가 더 효율적일떄가 있습니다.

            // 인터페이스
        }
    }


    // 인터페이스는 함수만 선언가능합니다.
    //  + 프로퍼티는 함수다.
    // 정의는 불가능합니다.
    public interface IAttacker
    {
        void Attack();

        public float Damage { get; set; }
    }

    public class Hero : IAttacker
    {
        public string Name = "Dummy";
        public float Hp = 100;

        public float Damage { get; set; } = 30;

        void IAttacker.Attack()
        {
            
        }
    }

   
}
