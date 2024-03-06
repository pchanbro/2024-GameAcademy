#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

void main()
{
	// 콘솔에서만 쓰일 기술
	// 콘솔 다루는 것은 일주일도 안남았다.
	// 다다음주면 콘솔 안쓴다. (콘솔게임 안만든다)
	// 이해안되면 이해하지 않아도 좋다.

	int oldGameTime = ::GetTickCount64(); // 현재 게임시간을 기억한다. 메인문 들어오자마자 했으니(0초)

	//GetTickCount => 게임이 시작하고 몇 ms가 지났는지?

	while (true)
	{
		// 1초에 한 번씩 나오도록 해주는 방법
		int currentGameTime = GetTickCount64();
		if (1000 < currentGameTime - oldGameTime)
		{
			system("cls");
			cout << "1초가 지났습니다. " << endl;
			oldGameTime = currentGameTime;
		}
		// 이 로직은 
		// 2D 애니메이션
		// 이미지 여러장을 체인지하는 형식으로 애니메이션을 주는데
		// 그 알고리즘이 이거다.
	}
}