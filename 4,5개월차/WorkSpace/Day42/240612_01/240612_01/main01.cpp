// rapidjson 붙이기.

// 보통은 C++ 라이브러리는
// include, lib 폴더 두 개 있다.

// include => .h
// lib=> .cpp 이기 때문에
// 보통 둘 다 붙여주는데
	
// 이번에 쓸 rapidjson은 include에 둘 다 들어있어 하나만 붙이면 된다.

// ThirdParty 폴더 -> 프로그램의 소스가 아니라 외부 라이브러리 파일들을 넣는 곳을 보통 ThirdParty라고 이름 붙여준다.


// 외부 파일(라이브러리 등) 을 쓸 때
// 프로젝트 우클릭 - 속성 - 구성(모든 구성) - 플랫폼(모든플랫폼) - C/C++ (추가 포함 디렉터리 편집(이게 include path)
// 추가 포함 디렉터리 편집 시 $(SolutionDir)을 경로에 사용해주면 컴퓨터마다 다른 경로를 프로젝트가 존재하는 파일을 찾아줘서
// 다른 컴퓨터에서도 사용할 수 있도록 만들어준다. 자세한 건 Day42 57분쯤 영상 확인

// rapidjson/example/simpledom/simpledom.cpp`
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <iostream>

using namespace rapidjson;

int main()
{
	// 1. Parse a JSON string into DOM.
	const char* json = "{\"project\":\"rapidjson\",\"stars\":10}";
	// 이 윗줄을 풀면 어떻게 들어가냐
	//{ "project" : "rapidjson", "stars": 10} 라고 볼 수 있다. 그러니 지금 json은 이와 같은 데이터를 담고 있는 데이터라 할 수 있다...
	Document d; // Dom이 Document
	d.Parse(json); // 사용할 데이터로 변환하는 과정, Json문자열을 Dom객체 안에 넣겠다.

	// 2. Modify it by DOM. doucument 안의 값을 수정할 수 있도록 만들어준다.
	{
		Value& s = d["stars"];
		s.SetInt(s.GetInt() + 1); //  stars의 값 10을 11로 변경하는 과정
	}
	{
		Value& s = d["project"];
		s.SetString("sbs academy");
	}
	// 3. Stringify the DOM , 문자열로 바꾸는 과정
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);
	d.Accept(writer);

	// Output {"project":"rapidjson","stars":11}
	std::cout << buffer.GetString() << std::endl;
	return 0;

	// 이 위 코드를 해석해보는게 코드를 읽어보는 과정이다.

	// 라이브러리를 사용
	//  - 예제코드를 원하는대로 수정할 수 있으면 사용할 수 있는것이다.
}