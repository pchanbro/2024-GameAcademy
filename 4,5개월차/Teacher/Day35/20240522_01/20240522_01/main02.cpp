#include <iostream>
#include <fstream>
using namespace std;

void main()
{
	// C++ 스타일

	//ifstream => 읽을때 (Read)
	//ofstream => 쓸때 (Write)


	/*cout << "SS" << endl;
	cin >> 변수;*/

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