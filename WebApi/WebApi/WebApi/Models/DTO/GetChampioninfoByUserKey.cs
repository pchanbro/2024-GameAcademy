namespace WebApi.Models.DTO
{

    // C# 컨벤션상
    // 클래스에서
    // 프로퍼티는 대문자 시작이고
    // 변수는 _시작 + private 변수 or protected 변수
    public class RequestDtoGetChampionInfoByUserKey
    {
        public int UserKey { get; set; }
    }

    public class ResponseDtoGetChampionInfoByUserKey
    {
        public int UserKey { get; set;}
        public int ChampionLevel { get; set;}
        public string ChampionName { get; set;} = string.Empty;

    }
}
