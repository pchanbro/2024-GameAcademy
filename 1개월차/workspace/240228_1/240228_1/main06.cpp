#include <iostream>
#include <windows.h>
using namespace std;

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}

void main()
{
	cout << "출력할 내용 ~~~" << endl;
	system("pause"); // 일시정지
	system("cls");   // clear screen 화면 싹지움.

	// 콘솔 색상바꾸기
	// 콘솔 폰트크기 바꾸기
}

// 숙제 1
	// 빙고게임 (vs Com)
	// 5*5 빙고판을 만들어주고
	// 1 ~ 25 까지 랜덤한 숫자가 적혀있다.
	// 내가 한 번 숫자를 입력하면
	// 내 빙고판에서 숫자하나 지워지고
	// 상대 빙고판에서 숫자하나 지워지고

	// 그다음 상대가 랜덤으로 숫자를 하나 입력
	// 내 빙고판에서 숫자하나 지워지고
	// 상대 빙고판에서 숫자하나 지워지고
	// 3줄이 빙고가되면 해당 유저 승리

	// 숙제 2
	// GOTO XY 사용해서 캐릭터 하나 만들기