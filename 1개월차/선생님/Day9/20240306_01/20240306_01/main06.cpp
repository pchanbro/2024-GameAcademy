#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;


void main()
{
	//콘솔에서만 쓰일기술이고
	//저희콘솔 다루는거 일주일도 안남았어요.
	//다다음주면 콘솔 안씁니다. (콘솔게임 안만들어요!)
	//이거 이해안되면 이해하지마세요.


	int oldGameTime = ::GetTickCount64(); // 현재 게임시간을 기억한다.	(0초)
	//GetTickCount => 게임이 시작하고 몇ms가 지났는지?

	while (true)
	{
		//1초에 한번씩
		int currentGameTime = GetTickCount64();
		if (1000 < currentGameTime - oldGameTime)
		{
			system("cls");
			cout << "1초가 지났습니다." << endl;
			oldGameTime = currentGameTime;
		}
		//2D 애니메이션
		//이미지 여러장을 체인지하는 형식으로 애니메이션을 주는데
		//그 알고리즘이 이거에요.

	}
}