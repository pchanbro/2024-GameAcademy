namespace CSharp_08
{
    internal class Program
    {
        static void Main(string[] args)
        {
            // STL => 배열, vector, map

            //1. Array
            int a = 1;

            //C++은 이렇게 선언하면
            // 동적할당이 됐습니다.
            int b = new int();
            b = 1;

            int[] arr = new int[10];

            //int* arr = new int[10];
            //int arr[10];


            //<C#은 클래스만 동적할당 됩니다.>


            for (int i = 0; i < arr.Length; i++)
            {
                arr[i] = i;
            }

            for (int i = 0; i < arr.Length; i++)
            {
                Console.WriteLine($"arr[{i}] : {arr[i]}");
            }

            // C#은 많이 편한언어입니다.

            // STL에 있어서는 
            // 거의 모든언어에 비해서 편합니다.
            // RUST, GoLang, JAVA, Kotln, 보다도 편합니다.
            // python, js에 와는 취향차이



            //vector 
            // vector => 가변 길이 배열
            // C++의 vector => C#의 List

            // C++에서는 
            // vector<int> myVec = {}; 하거나
            // vector<int> myVec; 해서
            // myVec.push_back(0); 하고 사용했는데

            //C#의 변수선언 (모든 변수 공통)
            //자료형 변수명 = new 자료형();
            // 일단 무조건 new를 붙여야 한다는거
            List<int> list = new List<int>();

            for (int i = 0; i < 100; i++)
            {
                list.Add(i);
            }

            //pop_back의 Index 버전 (몇번째 요소를 지워라)
            list.RemoveAt(8);
            //pop_back의 Value 버전 (값이 x인 요소를 지워라)
            list.Remove(0);

            //3번째인덱스로부터 10개 연속으로 지워라
            list.RemoveRange(3, 10);


            //C#에서 Predicate 가 보이면
            // CallBack Function 사용하겠다.
            // 람다식이라고해서
            // 함수를 선언과동시에, 매개변수로 넣을수도있습니다.
            list.RemoveAll(x => x % 2 == 0);
            // 이 위의 코드는 아래 코드와 같다
            //for (int i = list.Count - 1; i >= 0; i--)
            //{
            //    int x = list[i];
            //    if (x % 2 == 0)
            //    {
            //        list.RemoveAt(i);
            //    }
            //}

            list.ForEach(x => Console.WriteLine(x));

            // 보통 람다식을 쓰면 이렇게 길게 쓴다.
            list.ForEach(x =>
            {
                int aa = 0;
                int bb = 0;
                Console.WriteLine(x);
            });


            //map
            //map의 특징
            // key로 빠르게 찾을수있다.
            // 대신, 모든 애들 순회가 살짝 어렵다.

            // C#에서의 map은 무엇인가요?
            // Dictionary
            // map<string, int>

            Dictionary<string, int> dict = new Dictionary<string, int>();

            //map 요소 추가
            dict["T_Background"] = 0;
            //dict["S_Background"] = 1;
            dict.Add("S_Background", 1); // ->윗줄은 함수꼴로 한거 같은 효과다

            //ContainsValue => 느립니다.  O(N)
            //ContainsKey => 빨라요. O(LogN)

            dict.Remove("T_Background"); // remove(키값) 해주면 사라짐

            Console.WriteLine(dict["S_Background"]);
        }
    }
}


// 1) 변수 선언 + 사칙연산
// 2) if문, for문, while문 
// 3) STL 을 이 언어에는 어떻게 사용하는지?
// 4) 함수 콜 (매게변수의 값을 변경하는 방법) 
// 5) 그러면 C++에서 만들었던 숙제들을 지금당장 구현할수있는지?
// 6) 메모리구조. (Heap, Stack, Code, Data) (좀 큰프로젝트를 만들때 꼭 알아둘것.)
// 7) [클래스, 인터페이스] 사용방법만 익히시면됩니다.
//  - 프로그램 아키텍처 