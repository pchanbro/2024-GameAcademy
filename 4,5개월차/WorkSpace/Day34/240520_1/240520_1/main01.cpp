#include <iostream>

using namespace std;

void main()
{
    // ��Ʈ����

    int a = 4;
    printf("%d\n", a >> 2);

    //����Ʈ ����
    // >>  ��Ʈ�� ��ü������ ���������� �δ�. (���� ��������.)
    // <<  ��Ʈ�� ��ü������ �������� �δ�.


    // |, &
    // or ������
    // and ������

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
    //1110 (32��Ʈ) --> -2
    unsigned int b = ~1;
    cout << b << endl;

    // ǥ���
    int c = 1;
    int d = 10;

    // 2����, 16����
    int e = 0b11; // (3)
    printf("%d\n", e);
    int f = 0x11; // (17)
    printf("%d\n", f);

    int g = 0x0f; // (15)
    printf("%d\n", g);
}