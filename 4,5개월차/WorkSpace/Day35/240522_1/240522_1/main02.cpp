#include <iostream>
#include <fstream>
using namespace std;

void main()
{
	// C++��Ÿ��
	
	//ifstream => ������ (Read)
	//ofstream => ���� (Write)

	if (false)
	{
		ofstream ofs;
		ofs.open("test2.txt");

		int a = 3;
		ofs << a;
		ofs << endl;
		int b = 2;
		ofs << b;
		ofs.close();
		/*cout "SS" << endl;
		cin >> ����;  �� ����� ���� */
	}

	if (true)
	{
		ifstream ifs;
		ifs.open("test2.txt");

		int a;
		int b;
		ifs >> a;
		string line;
		ifs >> line;
		ifs >> b;
		ifs.close();

		cout << "a : " << a << endl;
		cout << "b : " << b << endl;
	}
}