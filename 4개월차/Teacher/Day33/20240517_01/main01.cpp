#include <iostream>
using namespace std;


int a = 0;
int b = 0;

void Run()
{
    cout << "Run" << endl;
}

void Run1(int argument1, int argument2)
{
    cout << "Run1 : " << argument1 << ", " << argument2 << endl;
}

int Add(int num1, int num2)
{
    return num1 + num2;
}

int main()
{
    // 함수포인터

    // - 함수포인터 : 진짜 많이 어려워요.

    // 함수포인터가 무엇인가?
    //  - 포인터 : 주소를 가르키는 자료형
    //  - 함수포인터 : 함수의 주소를 가르키는 자료형


    // - 함수도 메모리를 차지합니다.

    // int형은 4byte 메모리를 차지한다 배웠습니다.
    // 함수도 4byte 차지합니다. (모든함수가 4byte차지) 

    // 함수의 주소를 기억했다가 나중에 쓸수도있겠다.
    // 함수 포인터 - 다른언어 (콜백)

    // 함수포인터(콜백) : 함수의 주소를 기억했다가 나중에 사용하는 기법.

    // *
    // int포인터 :  int*
    // 함수포인터 : 함수반환형 네임스페이스::*변수명(매게변수)
    //          - ex) void (*myFunction1)(void) = &Run;
    // void포인터 : 치트키 느낌으로 어떤 주소든 담을수있다.
    //          - ex) void *myPointer = &Run;

    cout << "Run() 함수의 주소 : " << &Run << endl;
    void* myPointer = &Run;
    //void Run()

    void (*myFunction1)(void) = &Run;
    
    cout << "myPointer : " << myPointer << endl;

    // 함수를 담았으니 사용을 하는법:
    cout << "------------------------" << endl;
    myFunction1();


    // 여기까지가 함수포인터 기초


    // 응용 1. 매게변수가 있는 함수를 함수포인터로 써보자.
    //void Run1(int argument1, int argument2)
    //함수반환형 네임스페이스::*변수명(매게변수)
    void (*myFunction2)(int, int) = &Run1;
    myFunction2(10, 10);    
    //Run1(10, 10);


    // 응용 2. 반환자료형이 있는 함수를 함수포인터로 써보자.
    //int Add(int num1, int num2)
    int (*myFunction3)(int, int) = &Add;
    int addValue = myFunction3(2, 3);   //Add(2,3)
    cout << "addValue : " << addValue << endl;
    
    // 실습
    // 계산기를 만들건데
    // 0. + (Add) - (Minus) * (Multiply) / (Divide) 함수를 만든다.
    // 1. 숫자 2개를 입력받는다.
    // 2. (+ - / *) 중에 하나를 할수있도록 입력받는다.
    // 3. 2번을 실행하면, 함수포인터로 0번에서 만든 함수를 하나 받도록 한다.
    // 4. 함수포인터를 실행 후, 결과를 출력한다.
    // --> 간단하게 말하면, 계산기 만들건데 함수포인터를 사용해라.
    // 실습시간 8시 10분까지.

}
