#include <iostream>

using namespace std;

void main()
{
    // 비트연산

    int a = 4;
    printf("%d\n", a >> 2);

    //시프트 연산
    // >>  비트를 전체적으로 오른쪽으로 민다. (거의 쓴적없음.)
    // <<  비트를 전체적으로 왼쪽으로 민다.


    // |, &
    // or 연산자
    // and 연산자

    //0010
    //0110 and
    //--------
    //0010 => 2

    printf("2 & 6 : %d\n", 2 & 6);

    //0110 
    //0011 or
    //--------
    //0111 => 7
    printf("6 | 3 : %d\n", 6 | 3);

    //0001 not
    //-----
    //1110 (32비트) --> -2
    unsigned int b = ~1;
    cout << b << endl;

    // 표기법
    int c = 1;
    int d = 10;

    // 2진수, 16진수
    int e = 0b11; // (3)
    printf("%d\n", e);
    int f = 0x11; // (17)
    printf("%d\n", f);

    int g = 0x0f; // (15)
    printf("%d\n", g);
}