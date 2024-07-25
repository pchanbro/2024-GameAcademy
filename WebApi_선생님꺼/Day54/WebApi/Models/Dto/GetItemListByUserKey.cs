namespace WebApi.Models.Dto
{
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