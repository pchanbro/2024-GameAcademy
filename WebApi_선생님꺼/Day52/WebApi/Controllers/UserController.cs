using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using WebApi.Data;
using WebApi.Models.DB;

namespace WebApi.Controllers
{
    [ApiController]
    [Route("[controller]")]
    public class UserController : ControllerBase
    {
        private static int _newUserId = 1;
        private static List<User> _users = new List<User>();
        private readonly Context _context;

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
        public UserController(ILogger<UserController> logger, Context context) 
        { 
            _logger = logger;
            _context = context;
        }

        [HttpGet("TestGet")]
        public async Task<List<BsyTblUser>> GetBsyTblUsers()
        {
            return await _context.BsyTblUsers.ToListAsync();
        }


        [HttpGet()]
        public User Get([FromQuery]int id)
        {
            //foreach(var user in _users)
            //{
            //    if(user.Id == id)
            //    {
            //        return user;
            //    }
            //}

            //linq

            //users 안에 있는 리스트를
            //u라는 이름으로 순회하면서
            //u.Id == id 이면
            //배열이 나오는데,
            //그중에서 첫번째 요소를 가져오겠다.
            //첫번째요소 조차없으면 Default 값으로 가져오겠다.
            var rv = _users.Where(u => u.Id == id).FirstOrDefault();

            if (rv == null)
            {
                throw new Exception("Bad Request");
            }

            return rv;
        }

        [HttpPost()]
        public bool Create([FromQuery] string name, string email, string password)
        {
            User newUser = new User()
            {
                Id = _newUserId,
                Email = email,
                Password = password,
                Name = name
            };

            _users.Add(newUser);

            _newUserId++;

            return true;
        }

        [HttpPut()]
        public bool Update([FromQuery] int id, string email)
        {
            var user = _users.Where(u => u.Id == id).FirstOrDefault();

            if (user == null)
            {
                return false;
            }

            user.Email = email;

            return true;
        }

        [HttpDelete()]
        public bool Delete([FromQuery]int id)
        {
            User deleteUser = _users.Where(u => u.Id == id).FirstOrDefault();

            if (deleteUser == null)
            {
                return false;
            }

            _users.Remove(deleteUser);
            return true;

        }


    }
}
