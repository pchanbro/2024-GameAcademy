#include <iostream>

// 이름은 모두 대문자로 쓰는게 기본
#define ARRAY_SIZE 100
#define MY_NUMBER 1
#define MY_GG =
#define ADD(a,b) a + b
//여기서 \을 쓰면 다음줄까지 포함하겠다는 의미
#define ADD_AND_PRINT(a, b) printf("ADD Start : %d, %d\n", a, b);   \
							printf("ADD Result : %d\n", a + b);
using namespace std;

void main()
{
	// 매크로!
	// C++ 에만 존재하는 문법
	 
	// 사용법 
	// 위에 #define 이름 뭔가(숫자, = 이런거 다 들어감)
	// 이렇게 하면 '이름'이 '뭔가'를 대체해줌

	// 위에서 MY_GG를 = 이라고 했으니 아래와 같이 사용 가능
	int a MY_GG 1; // a에 1 대입
	cout << a << endl; // 1 출력됨

	int arr[ARRAY_SIZE] = {};

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		arr[i] = i;
	}
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		printf("arr[i] = %d\n", arr[i]);
	}

	int b = ADD(2, 3);
	printf("b : %d\n", b);
}