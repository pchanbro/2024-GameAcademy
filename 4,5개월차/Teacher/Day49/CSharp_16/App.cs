using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_16
{
    public class Data
    {
        public string Name { get; set; }
        public string Program { get; set; }
    }

    internal class App
    {
        private List<Data> _datas = new List<Data>();

        public void Run()
        {
            AddData("류성용", "A");
            AddData("하형빈", "B");
            AddData("봉영환", "C");
            AddData("류성용", "D");
            AddData("하형빈", "A");
            AddData("봉영환", "B");
            AddData("류성용", "C");
            AddData("하형빈", "D");
            AddData("봉영환", "A");
            AddData("류성용", "B");
            AddData("하형빈", "C");
            AddData("봉영환", "D");
            AddData("류성용", "A");
            AddData("하형빈", "B");
            AddData("봉영환", "C");
            AddData("류성용", "D");
            AddData("하형빈", "A");
            AddData("봉영환", "B");
            AddData("류성용", "C");
            AddData("하형빈", "D");
            AddData("봉영환", "A");
            AddData("류성용", "B");
            AddData("하형빈", "C");
            AddData("봉영환", "D");
            AddData("류성용", "A");
            AddData("하형빈", "B");
            AddData("봉영환", "C");

            DisplayData();

            // Group by : 데이터 컬럼을 리스트 묶는 방법
            var query = from d in _datas    // _datas에서 d라는 이름으로 가져와서
                        group d by d.Name into g    // d요소를 Name이라는 단위로 가져와서 그룹핑해줄것이다.
                        select g;                   // 그래서 g를 반환할것이다.


            //_datas에 들어간 정보중에서 Name별로 묶어서 데이터좀 이쁘게 보고싶다.

            foreach (var item in query)
            {
                Console.WriteLine($"{item.Key} : ");
                foreach (var item2 in item)
                {
                    Console.WriteLine($"{item2.Name}, {item2.Program}");
                }
            }




        }

        private void AddData(string name, string program)
        {
            _datas.Add(new Data()
            {
                Name = name,
                Program = program
            });
        }

        public void DisplayData()
        {
            foreach (var data in _datas)
            {
                Console.WriteLine($"Name: {data.Name}, Program: {data.Program}");
            }
        }

    }

}
