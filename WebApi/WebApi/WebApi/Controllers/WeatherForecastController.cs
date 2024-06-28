using Microsoft.AspNetCore.Mvc;
using System.Collections.Generic;

namespace WebApi.Controllers
{
    // Controller���� �Լ���
    // Client�� ��û�� �� �ִ� ���Ʈ�� �ȴ�.

    // �� �Ʒ� �� ���� attribute ��� �Ѵ�.
    [ApiController]
    [Route("[controller]")]

    public class WeatherForecastController : ControllerBase // ControllerBase�� �⺻������ �־���
    {
        private string[] Summaries = new[]
        {
            "Freezing", "Bracing", "Chilly", "Cool", "Mild", "Warm", "Balmy", "Hot", "Sweltering", "Scorching"
        };

        // �������
        private readonly ILogger<WeatherForecastController> _logger;

        public WeatherForecastController(ILogger<WeatherForecastController> logger)
        {
            _logger = logger;
        }
        // ��������� �ϴ� �ܿ��� ����, �߿����� ������ ���� ������ �˾ƾ� ��


        [HttpGet("Test")] // Ŭ���̾�Ʈ���� ������ �̸��� Test
        public List<int> Test()
        {
            // ������ ������ Ŭ���̾�Ʈ���� �����͸� ��û�ϰ� DB���� ������ �ִ°�
            // Ŭ���̾�Ʈ���� �����͸� ��û�޴°� >> �����
            // Ŭ���̾�Ʈ�� �����͸� �Ѱ��ִ°� >> �����

            List<int> values = new List<int>();
            for(int i = 0; i < 10; i++)
            {
                values.Add(i);
            }

            return values;
        }
    }
}
