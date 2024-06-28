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
            // chatGpt나 github copliot 이런 AI 쓰는것을 습관으로 들여라

            // 배울때 모르는 내용가지고 쓰는건 좋지 않다.

            // 그럼 언제 써야하나?
            // 아는데, 이거 이렇게하면 노가다를 줄이고 좀 빨리 할 수 있을것 같은데? 싶으면 써라

            // 모르는데 쓰면 -> 나중에 코드가 내 코드가 아니게 된다.

            // 회사에서 평가하는 잘하는 사람의 기준
            // - 친한사람이 잘하는 사람 (평가하는 사람의 기준)
            //      - 최대한 적 만들지 말고 유하게 넘어가기
            //      - 그리고 사실, 커뮤니케이션을 잘하면 친한사람이 많을 수 밖에 없다.
            // - 생산성이 높은사람
            //      - 어떤 일을 시켰을때 빨리하는 사람. 버그까지 없으면 금상첨화
            //      - 느리게해도 버그 있을 수 있다.
            //      - 빠르게 개발하는것과 느리게 개발하는것에서 버그차이는 사실 별로 없음

            // 최근 권고사직당한 10년차 개발자도 이런걸 모르는 사람도 있었다.

            // 일 잘한다고 평가받는사람이랑
            // 실제로 일 잘하는 사람은 다를 수 있다.
            // 실력이 있으면서 일 잘하는 사람처럼 보이는게 좋다.

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
            // Where의 즉시실행은 Find()

            result1.ToList();

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
            var item1 = items.Where(item => item.Name == "롱소드").FirstOrDefault();
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
            var userChampions = (from u in users
                                join c in champions
                                    on u.ChampionKey equals c.Key
                                select new
                                {
                                    ChampionKey = c.Key,
                                    ChampionName = c.Name,
                                    Level = u.Level
                                }).ToList(); // ToList 하면 실체화가 된다.

            foreach(var uc in userChampions)
            {
                Console.WriteLine($"{uc.ChampionName} : {uc.Level}");
            }
        }
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
