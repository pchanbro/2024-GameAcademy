using Microsoft.AspNetCore.Mvc;
using System.Collections.Generic;

namespace WebApi.Controllers
{
    // Controller안의 함수는
    // Client가 요청할 수 있는 라우트가 된다.

    // 이 아래 두 줄을 attribute 라고 한다.
    [ApiController]
    [Route("[controller]")]

    public class WeatherForecastController : ControllerBase // ControllerBase는 기본적으로 주어짐
    {
        private string[] Summaries = new[]
        {
            "Freezing", "Bracing", "Chilly", "Cool", "Mild", "Warm", "Balmy", "Hot", "Sweltering", "Scorching"
        };

        // 여기부터
        private readonly ILogger<WeatherForecastController> _logger;

        public WeatherForecastController(ILogger<WeatherForecastController> logger)
        {
            _logger = logger;
        }
        // 여기까지는 일단 외워서 쓰자, 중요하진 않은데 많은 내용을 알아야 함


        [HttpGet("Test")] // 클라이언트에게 보여줄 이름은 Test
        public List<int> Test()
        {
            // 서버의 목적은 클라이언트에서 데이터를 요청하고 DB에서 꺼내서 주는것
            // 클라이언트에서 데이터를 요청받는거 >> 방금함
            // 클라이언트에 데이터를 넘겨주는거 >> 방금함

            List<int> values = new List<int>();
            for(int i = 0; i < 10; i++)
            {
                values.Add(i);
            }

            return values;
        }
    }
}
