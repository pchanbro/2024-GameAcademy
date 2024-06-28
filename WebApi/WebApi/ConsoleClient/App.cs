using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleClient
{
    internal class App
    {
        public async Task<int> RunAsync()
        {
            // Server Client 구조에서 
            // 제일 중요한 
            // 동기/비동기 구조

            // async, await, Task 키워드

            // async 키워드 : 이함수는 비동기 함수다.
            // Task 키워드 : 이 함수는 비동기 함수, return형이 Task이다. (스레드)

            // await 키워드 : Async로 되어있는 비동기 함수를 완료될때까지 기다리겠다.
            //              : await + async 함수 (함수가 완전히 끝날때까지 기다렸다가 줘라) (스레드 정보가 필요 없게됨)
            //               이렇게하면 return값이 Task<자료형>(스레드를 리턴하여 스레드에 관한 정보를 얻음) 에서 자료형 으로 변한다.

            // 스레드 : 
            //   우리는 그동안 싱글스레드 환겨에서만 코딩했다
            //
            // 스레드는 코드를 실행시켜주는 주체
            // 스레드를 여러개 사용하면 멀티스레드

            // 프로그램이 식당이라 하면
            // 스레드는 직원  이라 하기도 한다.

            // 나중에 C++ 서버를 하게되면
            // IOCP (수백개의 스레드를 컨트롤하는 라이브러리)를 하게된다. 여기서 스레드를 다루는데 문제를 많이 발견한다.


            var client = new HttpClient();
            var request = new HttpRequestMessage(HttpMethod.Get, "http://localhost:5245/WeatherForecast/Test");
            var response = await client.SendAsync(request);
            response.EnsureSuccessStatusCode();
            Console.WriteLine(await response.Content.ReadAsStringAsync());


            // await 했냐 안했냐(동기냐 비동기냐)에 따라 return 값이 다르다.
            int a = await GetMyValue();
            Task<int> b = GetMyValue();

            return 5;
        }


        public async Task<int> GetMyValue()
        {
            await Task.Delay(1000);  // 새로운 스레드를 만들어서 걔가 1초 대기할때까지 기다리는거

            //Thread.Sleep(1000);  // 현재 내 스레드를 1초동안 잠재우는것, 위랑 같은 의미

            return 1;
        }
    }
}
