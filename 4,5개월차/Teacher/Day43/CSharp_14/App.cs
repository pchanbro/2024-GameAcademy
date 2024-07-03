using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_14
{
    public interface ICreature
    {
        string Name { get; set; }
        float Hp {  get; set; }
        void Attack(ICreature target);

        float Damage { get; set; }
    }

    public interface IAttacker
    {
    }

    // C++은 상속받을 때 여러 개의 class를 상속받을 수 있는데 C#에서는 그게 안된다.
    // C#에서는 한 개의 class만 상속받거나 여러 개의 interface를 상속 받는다.
    public class Monster1 : ICreature, IAttacker
    {
        public float Damage { get; set; } = 30;
        public string Name { get; set; } = "Hero1";
        public float Hp { get; set; } = 100;

        void ICreature.Attack(ICreature target)
        {
            target.Hp -= this.Damage;
        }
    }



    public class Hero : ICreature
    {
        public float Damage { get; set; } = 30;
        public string Name { get; set; } = "Hero1";
        public float Hp { get; set; } = 100;
        
        void ICreature.Attack(ICreature target)
        {
            target.Hp -= this.Damage;
        }
    }

    public class Monster : ICreature
    {
        public float Damage { get; set; } = 30;
        public string Name { get; set; } = "Monster01";
        public float Hp { get; set; } = 100;

        void ICreature.Attack(ICreature target)
        {
            target.Hp -= this.Damage;
        }
    }

    internal class App
    {
        public void Run()
        {
            // Hero, Monster 클래스 하나씩 생성해서
            // 한대씩 계속 때려서 
            // 누가 이겼는지 출력해주는 프로그램 

            List<ICreature> creatures = new List<ICreature>();
            creatures.Add(new Hero());
            creatures.Add(new Monster());

            while (true)
            {
                creatures[0].Attack(creatures[1]);
                Console.WriteLine($"{creatures[0].Name}의 공격");
                if (creatures[1].Hp < 0)
                {
                    Console.WriteLine($"{creatures[1].Name}의 HP가 0 이하가 되었습니다.");
                    Console.WriteLine($"{creatures[0].Name}의 승리");
                    break;
                }
                Console.WriteLine($"{creatures[1].Name}의 남은 Hp : {creatures[1].Hp}");

                creatures[1].Attack(creatures[0]);
                Console.WriteLine($"{creatures[1].Name}의 공격");
                if (creatures[0].Hp < 0)
                {
                    Console.WriteLine($"{creatures[0].Name}의 HP가 0 이하가 되었습니다.");
                    Console.WriteLine($"{creatures[1].Name}의 승리");
                    break;
                }
                Console.WriteLine($"{creatures[0].Name}의 남은 Hp : {creatures[0].Hp}");
            }


            // 0번 인덱스와 1번 인덱스가 서로 싸우게 해주면 된다.

            // Hero 클래스에 SpecialAttack 까지 넣어보면 더 좋다.
            // 뭔가 더 작용하게끔
        }
    }
}
