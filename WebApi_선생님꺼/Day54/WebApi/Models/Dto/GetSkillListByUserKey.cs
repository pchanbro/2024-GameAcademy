namespace WebApi.Models.Dto
{
    public class RequestDtoGetSkillListByUserKey
    {
        public int UserKey { get; set; }
    }

    public class ResponseDtoGetSkillListByUserKey
    {
        public List<ResponseDtoGetSkillListByUserKeyElement> List { get; set; }
    }

    public class ResponseDtoGetSkillListByUserKeyElement
    {
        public int SkillKey { get; set; }
        public string SkillName { get; set; } = string.Empty;
    }
}