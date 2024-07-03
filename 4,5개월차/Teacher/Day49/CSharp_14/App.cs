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
        float Hp { get; set; }
    }

    public interface IAttacker
    {
        void Attack(ICreature target);

        float Damage { get; set; }
    }

    public class Hero : IAttacker, ICreature
    {
        public float Damage { get; set; } = 30;
        public string Name { get; set; } = "Hero";
        public float Hp { get; set; } = 100;

        public void Attack(ICreature target)
        {
            target.Hp -= Damage;
            Console.WriteLine($"{target.Name}을 공격하였습니다.");
            Console.WriteLine($"{target.Name}의 남은체력 : {target.Hp}");
        }
    }

    public class Monster1 : IAttacker, ICreature
    {
        public float Damage { get; set; } = 5;
        public string Name { get; set; } = "SCV";
        public float Hp { get; set; } = 40;

        public void Attack(ICreature target)
        {
            target.Hp -= Damage;
            Console.WriteLine($"{target.Name}을 공격하였습니다.");
            Console.WriteLine($"{target.Name}의 남은체력 : {target.Hp}");
        }
    }

    public class Monster2 : ICreature
    {
        public string Name { get; set; } = "Lava";
        public float Hp { get; set; } = 100;
    }


    internal class App
    {
        public void Run()
        {
            // 9시까지
            // Hero, Monster 클래스 하나씩 생성해서
            // 한대씩 계속 때려서
            // 결국 누가이겼는지 출력해주는 프로그램

            List<ICreature> creatures = new List<ICreature>();
            creatures.Add(new Hero());
            creatures.Add(new Monster2());

            // 0번인덱스와 1번인덱스가 서로 싸우게 해주면됩니다.

            while (true)
            {
                if (creatures[0].Hp <= 0)
                {
                    break;
                }

                if (creatures[1].Hp <= 0)
                {
                    break;
                }

                //is 연산자는 뒤의 자료형을 상속받았는지를 체크해주는 연산자다.
                if (creatures[0] is IAttacker)
                {
                    //as 연산자는 형변환입니다. (부모 => 자식으로가는..)
                    //like dynamic_cast
                    //IAttacker attacker = creatures[0] as IAttacker;
                    IAttacker attacker = (IAttacker)creatures[0];

                    if (attacker != null)
                    {
                        attacker.Attack(creatures[1]);
                    }
                }

                if (creatures[1] is IAttacker)
                {
                    //as 연산자는 형변환입니다. (부모 => 자식으로가는..)
                    //like dynamic_cast
                    //IAttacker attacker = creatures[1] as IAttacker;
                    IAttacker attacker = (IAttacker)creatures[1];

                    if (attacker != null)
                    {
                        attacker.Attack(creatures[0]);
                    }
                }
            }


            // Hero 에클래스에 SpetialAttack 까지 넣어서
            // 뭔가 더 작용하게끔.
        }
    }
}
