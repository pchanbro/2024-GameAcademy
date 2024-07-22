namespace WebApi.Models.DTO
{

    // C# 컨벤션상
    // 클래스에서
    // 프로퍼티는 대문자 시작이고
    // 변수는 _시작 + private 변수 or protected 변수
    public class RequestDtoGetItemListByUserKey
    {
        public int UserKey { get; set; }
    }

    public class ResponseDtoGetItemListByUserKey
    {
        public List<ResponseDtoGetItemListByUserKeyElement> List { get; set; }
    }

    public class ResponseDtoGetItemListByUserKeyElement
    {
        public int ItemKey { get; set; }
        public string ItemName { get; set; } = string.Empty;
    }
}
