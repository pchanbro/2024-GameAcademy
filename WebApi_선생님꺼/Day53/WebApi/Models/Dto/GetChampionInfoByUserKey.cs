namespace WebApi.Models.Dto
{
    public class RequestDtoGetChampionInfoByUserKey
    {
        public int UserKey { get; set; }
    }

    public class ResponseDtoGetChampionInfoByUserKey
    {
        public int UserKey { get; set; }
        public int ChampionLevel { get; set; }
        public string ChampionName { get; set; } = string.Empty;
    }
}