using Microsoft.AspNetCore.Mvc;

namespace WebApi.Controllers
{
    // 제대로된 프레임워크나
    // 제대로된 엔진
    // 블랙박스
    // => 우리가 실제로 코드를 볼 순 없지만,
    //  우리가 못보는곳에서 무언가를 하는...

    // builder.Services.AddControllers();
    // => 컨트롤러를 쓰겠다.

    // 모든 컨트롤러는 종속성이 생성됩니다.
    // builder안에 내가 원하는 서비스를 집어넣으면
    // 생성자에서 다 받을 수 있다.
    // builder => 모든 서비스를 알아서 잘 딱 맞게 생성자에 원하는 내용을 넣어준다.

    // ILogger<객체> 가장 기본적인 ASP .NET 서버의 logger 형태이다.

    [ApiController]
    [Route("[controller]")]
    public class UserController : ControllerBase
    {
        private List<User> _users = new List<User>();
        //Get Method
        //id를 통해서 User정보 조회

        //Post Method
        //유저를 새롭게 추가

        //Put Method
        //Id와 Email을 넣으면
        //해당 Id의 Email이 변경되도록 수정

        //Delete Method
        //Id를 넣으면
        //해당 유저가 삭제되게 수정

        private readonly ILogger<UserController> _logger;
        public UserController(ILogger<UserController> logger) 
        { 
            _logger = logger;
        }

        [HttpGet()]
        public List<int> Test1([FromQuery]int id, string name)
        {
            return new List<int>() { id, 9,8,7,6,5,4,3,2,1,0 };
        }

        [HttpPost()]
        public List<int> Test2()
        {
            return new List<int>() { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
        }

        [HttpPut()]
        public List<int> Test3()
        {
            return new List<int>() { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
        }

        [HttpDelete()]
        public List<int> Test4()
        {
            return new List<int>() { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
        }

        // HTTP 통신 특징
        // Method를 같이 보내게 되어있다.
        // URL + Method를 통해서 어떤 Controller의 어떤 함수로 접근할건지 
        // Method 중에 하나가 GET
        // GET, POST
        // PUT, DELETE

        // 좋은 코드는 함수명만봐도 대충 뭐하는앤지 알아야한다.
        // GetUserData
        // UpdateUserData
        // 특정 데이터를 진짜 극도로 아껴야하는 프로젝트에서는
        // 저 글자수마저 데이터가 아깝다라는 생각을 하게된다.

        // Method에 의미를 담자

        // Method Get에 User Controller 함수를 호출하면
        // User를 Get 해주는

        // Method POST에 User Controller 함수를 호출하면
        // User를 Create 해주는

        // Method PUT에 User Controller 함수를 호출하면
        // User를 Update 해주는

        // Method DELETE에 User Controller 함수를 호출하면
        // User를 DELETE 해주는

        // API로 만들자 (REST Api 규약)

        //-----------------------------------------------
        // 축약버전
        //-----------------------------------------------

        // Method Get에 User Controller 함수를 호출하면
        // User를 Get 해주는

        // Method POST에 User Controller 함수를 호출하면
        // User의 정보가 변하게 해주는
    }
}
