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
            // LINQ (Code Query) (Language-Integrated Query)
            // 지금까지 데이터 테이블이 되게 많았다.
            // 테이블을 컨트롤할 수 있는 무언가가 있으면 편리하다.
            // 테이블을 컨트롤하는 도구
            //   - DB에서는 Query라고 부른다.

            // 코드쿼리

            // LINQ를 제공하는 언어도 있고, 제공하지 않는 언어도 있다.
            // 선생님의 생각으로
            // C#의 가장 강력한 기능 중 하나는 LINQ가 잘 되어 있다는것


            // 게임 클라이언트 개발자를 생각한다면
            // C#을 배울때는 Unity (.net framwork)까지 생각한다. 
            List<int> intList = new List<int>(); // 그러니 객체 선언까지 다 해줘라

            for(int i = 0; i < 1000; i++)
            {
                intList.Add(i);
            }

            // 기본적으로 데이터를 뽑을 때
            // Filter기능을 많이쓴다. (Where) (DB : Where)
            // 예를 들면 데이터중에 어떤어떤 값을 가진애들만 추출하고싶다. 할 때 쓴다.

            // LINQ 사용법이 두 가지
            var result1 = intList.Where(x => x % 2 == 0);

            // 저 코드가 DB Query 문법이랑 되게 유사하게 생겼다.
            // DB내용을 그대로 써야하는 경우에 자주 쓴다.
            var result2 = (from x in intList 
                           where x % 2 == 0 
                           select x);

            result1.ToList();

            // linq
            // List가 나오길 기대했는데
            // IEnumerable<int> 가 반환됩니다.
            //  IEnumerable => 잠재적 리스트
            //   [아 나는 intList 라는 애에서
            //    x % 2 == 0 이것만 추출할거야.]
            // 뽑아오는 코드를 실행해야 그때 실행이된다.
            // 뽑아오는 코드 : ToList()


            // 숙제풀이 한 내용 class / List 만들고
            // 챔피언 Table에서 Key가 1인 내용 출력해보기 


            //List<champion> championTable = new List<champion>();
            //championTable.Add(new champion()
            //{
            //    Key = 1,
            //    Name = "Garen"
            //});

            //championTable.Add(new champion()
            //{
            //    Key = 2,
            //    Name = "Garen"
            //});

            //List<item> itemTable = new List<item>();
            //itemTable.Add(new item()
            //{
            //    Key = 1,
            //    Name = "shoes"
            //});

            //itemTable.Add(new item()
            //{
            //    Key = 2,
            //    Name = "Long Sword"
            //});

            //itemTable.Add(new item()
            //{
            //    Key = 3,
            //    Name = "Knife"
            //});

            //List<skill> skillTable = new List<skill>();
            //skillTable.Add(new skill()
            //{
            //    Key = 1,
            //    Name = "실명"
            //});

            //skillTable.Add(new skill()
            //{
            //    Key = 2,
            //    Name = "이속증가"
            //});

            //skillTable.Add(new skill()
            //{
            //    Key = 3,
            //    Name = "침묵"
            //});

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

            // LINQ
            var item1 = items.Where(item => item.Name == "롱소드").FirstOrDefault(); // Where의 즉시실행은 Find()
            var users1 = users.OrderBy(u => u.Level).ToList(); // 오름차순
            var users2 = users.OrderByDescending(u=> u.Level).ToList(); // 내림차순
            // users.Distinct() // 중복데이터 제거
            // users.Any (데이터가 1개라도 있는지? 있으면 true, 없으면 false)
            //if(items.Where(i => i.Name == "이거있나?").Any())
            //{
            // 오라적용
            //}
            // items.Min() items.Max()
            // items.Take(N) (몇개만 가져오겠다)
            // items.Skip(N) (몇개를 스킵하겠다)

            // 한 페이지에 100개를 보여줘야 하는데
            // 지금 327번째 페이지라고 하자
            // items.Skip(326 * 100).Take(100) 하면 가져올 수 있다.

            // items.GroupBy
            // items.Join




            //|Key|UserName|SkillName|
            //|---|---|---|
            //|1|티모|실명|
            //|2|티모|이속증가|
            //|3|가렌|침묵|

            // 실행했을때 1회
            // 조회했을때만 조금 문제가 생긴다.
            // JOIN 이 결과적으로는 조회를 많이하기 때문에
            // 잘못쓰면 많이 느림
            // JOIN을 어쩔 수 없이
            // 3중조인 4중조인 10중조인 


            // Join - 2가지
            // Query에 쓰는 내용을 그대로 가져오는 일이 많기 때문에
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


            // join 두번째 방법
            var userChampions2 = (from u in users
                                join c in champions
                                    on u.ChampionKey equals c.Key
                                select new
                                {
                                    ChampionKey = c.Key,
                                    ChampionName = c.Name,
                                    Level = u.Level
                                }).ToList(); // ToList 하면 실체화가 된다.

            foreach(var uc in userChampions2)
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

                //userSkill => list로 되어있음
                foreach (var skill in userSkill)
                {
                    Console.WriteLine($"{skill.Key}");
                }
            }



            // 1. 챔피언별로 스킬리스트 가져오기 (이름포함)
            // 2. 챔피언별로 아이템리스트 가져오기
            // 3. 챔피언별로 레벨 가져오기

            // query 조회하여 UserChampion  완성하기.
            List<UserChampion> userChampions = new List<UserChampion>();

            //우직하게 넣는 방법
            //userChampions.Add(new UserChampion()
            //{
            //    ChampionInfo = new Champion()
            //    {
            //        Key = 1,
            //        Name = "티모"
            //    },
            //
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
            //
            //    Level = 2,
            //
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
                                join champion in champions   // 조회하는 테이블에 champions를 추가한다.
                                    on u.ChampionKey equals champion.Key // 추가할때, user의 championKey와 champion.key가 동일한거를 기준으로 묶어서 조회한다.
                                select new
                                {
                                    ChampionKey = champion.Key,
                                    ChampionName = champion.Name,
                                    UserLevel = u.Level,
                                    UserKey = u.Key
                                };

            List<int> userKeys = new List<int>() { 1, 2 };

            //DB쪽할때는, 퍼포먼스 생각, 오래걸리지 않도록 해줘야 한다.
            foreach (var u in userKeys)
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
                foreach (var skill in uc.Skills)
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

    // 이 밑에는 내가 했던거 get, set을 안넣어줬네
    //public class champion
    //{
    //    public int Key;
    //    public string Name;
    //}

    //public class item
    //{
    //    public int Key;
    //    public string Name;
    //}

    //public class skill
    //{
    //    public int Key;
    //    public string Name;
    //}

    //public class user
    //{
    //    public int Key;
    //    public champion ChampionName;
    //    public int Level;
    //}

    //public class userItem
    //{
    //    public int Key;
    //    public int UserKey;
    //    public int ItemKey;
    //}

    //public class userSkill
    //{
    //    public int Key;
    //    public int UserKey;
    //    public int Skillkey;
    //}
}
