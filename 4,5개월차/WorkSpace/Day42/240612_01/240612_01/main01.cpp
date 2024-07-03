// rapidjson ���̱�.

// ������ C++ ���̺귯����
// include, lib ���� �� �� �ִ�.

// include => .h
// lib=> .cpp �̱� ������
// ���� �� �� �ٿ��ִµ�
	
// �̹��� �� rapidjson�� include�� �� �� ����־� �ϳ��� ���̸� �ȴ�.

// ThirdParty ���� -> ���α׷��� �ҽ��� �ƴ϶� �ܺ� ���̺귯�� ���ϵ��� �ִ� ���� ���� ThirdParty��� �̸� �ٿ��ش�.


// �ܺ� ����(���̺귯�� ��) �� �� ��
// ������Ʈ ��Ŭ�� - �Ӽ� - ����(��� ����) - �÷���(����÷���) - C/C++ (�߰� ���� ���͸� ����(�̰� include path)
// �߰� ���� ���͸� ���� �� $(SolutionDir)�� ��ο� ������ָ� ��ǻ�͸��� �ٸ� ��θ� ������Ʈ�� �����ϴ� ������ ã���༭
// �ٸ� ��ǻ�Ϳ����� ����� �� �ֵ��� ������ش�. �ڼ��� �� Day42 57���� ���� Ȯ��

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
	// �� ������ Ǯ�� ��� ����
	//{ "project" : "rapidjson", "stars": 10} ��� �� �� �ִ�. �׷��� ���� json�� �̿� ���� �����͸� ��� �ִ� �����Ͷ� �� �� �ִ�...
	Document d; // Dom�� Document
	d.Parse(json); // ����� �����ͷ� ��ȯ�ϴ� ����, Json���ڿ��� Dom��ü �ȿ� �ְڴ�.

	// 2. Modify it by DOM. doucument ���� ���� ������ �� �ֵ��� ������ش�.
	{
		Value& s = d["stars"];
		s.SetInt(s.GetInt() + 1); //  stars�� �� 10�� 11�� �����ϴ� ����
	}
	{
		Value& s = d["project"];
		s.SetString("sbs academy");
	}
	// 3. Stringify the DOM , ���ڿ��� �ٲٴ� ����
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);
	d.Accept(writer);

	// Output {"project":"rapidjson","stars":11}
	std::cout << buffer.GetString() << std::endl;
	return 0;

	// �� �� �ڵ带 �ؼ��غ��°� �ڵ带 �о�� �����̴�.

	// ���̺귯���� ���
	//  - �����ڵ带 ���ϴ´�� ������ �� ������ ����� �� �ִ°��̴�.
}