using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_15
{
    internal class App
    {
        public void Run()
        {
            // LINQ (Code Query)
            // 저희가 데이터 테이블이 되게 많았습니다.
            // 테이블을 컨트롤할수있는 무언가가 있으면 편리하다.
            // 테이블을 컨트롤하는 일
            //   - DB에서는 Query라고 부릅니다.

            // 코드쿼리 (Language-Integrated Query)

            // LINQ를 제공하는언어도 있고, 제공하지 않는 언어
            // 그리고 저만의 생각일 수도 있지만,
            // C#에서의 가장 강력한 기능중하나는 LINQ가 잘되어있다는 것.


            // 게임클라이언트 개발자
            // C# 을 배울떄는 Unity (.net framework)
            List<int> intList = new List<int>();

            for (int i = 0; i < 1000; i++)
            {
                intList.Add(i);
            }

            // 기본적으로 데이터를 뽑을때 
            // Filter기능을 많이써요. (Where) (DB : Where)
            // 예를들면 데이터중에 어떤어떤 값을 가진애들만 추출하고싶다.

            // linq 사용법이 두가지
            var result1 = intList.Where(x => x % 2 == 0);

            // 저 코드가 DB Query 문법이랑 되게 유사하게 생겼습니다.
            // DB내용을 그대로 써야하는 경우에 자주 씁니다.
            var result2 = (from x in intList
                            where x % 2 == 0
                            select x);

            //linq 
            //List가 나오길 기대했는데
            //IEnumerable<int> 가 반환됩니다.
            // IEnumerable => 잠재적 리스트
            //  [아 나는 intList 라는 애에서
            //   x % 2 == 0 이것만 추출할거야.]
            // 뽑아오는 코드를 실행해야 그때 실행이됩니다.
            // 뽑아오는코드 : ToList()


            // 숙제풀이 한내용 class / List 만들고
            // 챔피언 Table에서 Key가 1인내용 출력해보기
            // 9시 10분까지

            List<Champion> champions = new List<Champion>
            {
                new Champion { Key = 1, Name = "티모" },
                new Champion { Key = 2, Name = "가렌" }
            };

            // Initialize Item list
            List<Item> items = new List<Item>
            {
                new Item { Key = 1, Name = "신발" },
                new Item { Key = 2, Name = "단검" },
                new Item { Key = 3, Name = "롱소드" }
            };

            // Initialize Skill list
            List<Skill> skills = new List<Skill>
            {
                new Skill { Key = 1, Name = "실명" },
                new Skill { Key = 2, Name = "이속증가" },
                new Skill { Key = 3, Name = "침묵" }
            };

            // Initialize User list
            List<User> users = new List<User>
            {
                new User { Key = 1, ChampionKey = 1, Level = 2 },
                new User { Key = 2, ChampionKey = 2, Level = 1 }
            };

            // Initialize UserItem list
            List<UserItem> userItems = new List<UserItem>
            {
                new UserItem { Key = 1, UserKey = 1, ItemKey = 1 },
                new UserItem { Key = 2, UserKey = 1, ItemKey = 2 },
                new UserItem { Key = 3, UserKey = 2, ItemKey = 2 },
                new UserItem { Key = 4, UserKey = 2, ItemKey = 3 }
            };

            // Initialize UserSkill list
            List<UserSkill> userSkills = new List<UserSkill>
            {
                new UserSkill { Key = 1, UserKey = 1, SkillKey = 1 },
                new UserSkill { Key = 2, UserKey = 1, SkillKey = 2 },
                new UserSkill { Key = 3, UserKey = 2, SkillKey = 3 }
            };


            //LINQ
            var item1 = items.Where(item => item.Name == "롱소드").FirstOrDefault();
            var users1 = users.OrderBy(u => u.Level).ToList();  // 오름차순
            var users2 = users.OrderByDescending(u => u.Level).ToList();    //내림차순
            // users.Distinct() // 중복데이터 제거
            // users.Any (데이터가 1개라도 있는지? 있으면 true, 없으면 false)
            //if(items.Where(i => i.Name == "이거있나?").Any())
            //{
            //    //오라적용
            //}
            // items.Min() items.Max()
            // items.Take(N) (몇개만 가져오겠다.)
            // items.Skip(N) (몇개를 스킵하겟다.)

            // 한페이지에 100개를 보여줘야하는데
            // 지금 327번째 페이지  
            // items.Skip(326 * 100).Take(100)


            // items.GroupBy
            // items.Join

            // Join - 2가지
            // Query에 쓰는 내용을 그대로 가져오는 일이 많기때문에
            var userChampion = users.Join(
                    champions,  //조인할 테이블
                    user => user.ChampionKey,
                    champion => champion.Key,
                    (user, champion) => new
                    {
                        ChampionKey = champion.Key,
                        ChampionName = champion.Name,
                        Level = user.Level
                    }).ToList();

            // join 두번째방법
            var userChampions2 = (from u in users
                                 join c in champions
                                     on u.ChampionKey equals c.Key
                                 select new
                                 {
                                     ChampionKey = c.Key,
                                     ChampionName = c.Name,
                                     Level = u.Level
                                 }).ToList();

            foreach (var uc in userChampions2)
            {
                Console.WriteLine($"{uc.ChampionName} : {uc.Level}");
            }


            // GroupBy - 특정요소를 하나받아서, Group으로 묶어줍니다.
            //           특정요소 : Key ,
            //           Value(본체) : 특정요소를 가지고있는 List 
            var list = userSkills.GroupBy(u => u.UserKey).ToList();

            foreach (var userSkill in list)
            {
                Console.WriteLine($"{userSkill.Key}스킬 : ");

                //userSkill => list
                foreach (var skill in userSkill)
                {
                    Console.WriteLine($"{skill.Key}");
                }
            }


            // query 조회하여 UserChampion  완성하기.
            List<UserChampion> userChampions = new List<UserChampion>();

            //userChampions.Add(new UserChampion()
            //{
            //    ChampionInfo = new Champion()
            //    {
            //        Key = 1,
            //        Name = "티모"
            //    },
            //    Items = new List<Item>()
            //    {
            //        new Item()
            //        {
            //            Key = 1,
            //            Name = "신발",
            //        },
            //        new Item()
            //        {
            //            Key = 2,
            //            Name = "단검",
            //        }
            //    },
            //    Level = 2,
            //    Skills = new List<Skill>()
            //    {
            //        new Skill()
            //        {
            //            Key = 1,
            //            Name = "실명"
            //        },
            //        new Skill()
            //        {
            //            Key = 2,
            //            Name = "이속증가"
            //        }
            //    }
            //});


            var championQuery = from u in users //users를 u라고 칭하면서 순회한다.
                                join chapion in champions   // 조회하는 테이블에 champions를 추가한다.
                                    on u.ChampionKey equals chapion.Key // 추가할때, user의 championKey와 champion.key가 동일한거를 기준으로 묶어서 조회한다.
                                select new
                                {
                                    ChampionKey = chapion.Key,
                                    ChampionName = chapion.Name,
                                    UserLevel = u.Level,
                                    UserKey = u.Key
                                };

            List<int> userKeys = new List<int>() { 1, 2 };

            //DB쪽할때는, 퍼포먼스 생각
            foreach(var u in userKeys)
            {
                userChampions.Add(new UserChampion()
                {
                    ChampionInfo = (from user in users //users를 user라고 칭하면서 순회한다.
                                    where user.Key == u // user중에 key가 u인것만 조회한다.
                                    join champion in champions   // 조회하는 테이블에 champions를 추가한다.
                                    on user.ChampionKey equals champion.Key // 추가할때, user의 championKey와 champion.key가 동일한거를 기준으로 묶어서 조회한다.
                                   select new Champion()
                                   {
                                       Key = champion.Key,
                                       Name = champion.Name
                                   }).FirstOrDefault() ?? new Champion(),

                    Level = (from user in users
                            where user.Key == u
                            select user).FirstOrDefault()?.Level ?? 0,
                    // ?. 은 앞에거 null이면 전체를 null로 반환한다

                    Items = (from user in users
                            where user.Key == u
                            join userItem in userItems
                                on user.Key equals userItem.UserKey
                            join item in items
                                on userItem.ItemKey equals item.Key
                            select new Item()
                            {
                               Key = userItem.ItemKey,
                               Name = item.Name
                            }).ToList(),
                    UserKey = u,
                   
                    Skills = (from user in users
                              where user.Key == u
                              join userSkill in userSkills
                                on user.Key equals userSkill.UserKey
                              join skill in skills
                                on userSkill.SkillKey equals skill.Key
                              select new Skill()
                              {
                                  Key = skill.Key,
                                  Name = skill.Name
                              }).ToList()
                });
            }


            foreach (var uc in userChampions)
            {
                Console.WriteLine($"{uc.UserKey} : ");
                Console.WriteLine($"  level : {uc.Level}");
                Console.WriteLine($"  ChampionInfo : ");
                Console.WriteLine($"    Key : {uc.ChampionInfo.Key}");
                Console.WriteLine($"    Name : {uc.ChampionInfo.Name}");
                Console.WriteLine($"  Skills : ");
                foreach (var skill in  uc.Skills)
                {
                    Console.WriteLine($"    Key : {skill.Key}");
                    Console.WriteLine($"    Name : {skill.Name}");
                }
                Console.WriteLine($"  Items : ");
                foreach (var item in uc.Items)
                {
                    Console.WriteLine($"    Key : {item.Key}");
                    Console.WriteLine($"    Name : {item.Name}");
                }
            }
            

        }
    }

    public class UserChampion
    {
        public int UserKey { get; set; }
        public Champion ChampionInfo { get; set; }
        public int Level { get; set; }
        public List<Skill> Skills { get; set; }
        public List<Item> Items { get; set; }
    }


    public class Champion
    {
        public int Key { get; set; }
        public string Name { get; set; }
    }

    public class Item
    {
        public int Key { get; set; }
        public string Name { get; set; }
    }

    public class Skill
    {
        public int Key { get; set; }
        public string Name { get; set; }
    }

    public class User
    {
        public int Key { get; set; }
        public int ChampionKey { get; set; }
        public int Level { get; set; }
    }

    public class UserItem
    {
        public int Key { get; set; }
        public int UserKey { get; set; }
        public int ItemKey { get; set; }
    }

    public class UserSkill
    {
        public int Key { get; set; }
        public int UserKey { get; set; }
        public int SkillKey { get; set; }
    }
}
