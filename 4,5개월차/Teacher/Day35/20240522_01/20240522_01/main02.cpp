#include <iostream>
#include <fstream>
using namespace std;

void main()
{
	// C++ ��Ÿ��

	//ifstream => ������ (Read)
	//ofstream => ���� (Write)


	/*cout << "SS" << endl;
	cin >> ����;*/

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
	}

	if (true)
	{
		ifstream ifs;
		ifs.open("test2.txt");

		int a;
		int b;
		ifs >> a;
		ifs >> b;
		ifs.close();

		cout << "a : " << a << endl;
		cout << "b : " << b << endl;
	}


}