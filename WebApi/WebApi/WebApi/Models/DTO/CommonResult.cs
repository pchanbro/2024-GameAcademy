namespace WebApi.Models.DTO
{
    // template
    public class CommonResult<T>
    {
        public bool IsSuccess { get; set; } = false;
        public string Message { get; set; } = string.Empty;
        public EStatusCode StatusCode { get; set; } = EStatusCode.OK;
        public T Data { get; set; }
    }

    public enum EStatusCode
    { 
        OK,
        NotFoundEntity,
        ServerException
    }

    public class CommonException : Exception 
    {
        protected EStatusCode _statusCode = EStatusCode.OK;

        public int StatusCode => (int)_statusCode;

        protected object _data;
        public object Data => _data; // 얘는 getter임

        public CommonException(EStatusCode statusCode, string message, object data = null) : base(message) 
        { 
            _statusCode = statusCode;
            _data = data;
        }

        // 모든 클래스는 ToString를 가지고 있다
        public override string ToString()
        {
            return $"[{StatusCode}] {this.Message}";
        }
    }

}
