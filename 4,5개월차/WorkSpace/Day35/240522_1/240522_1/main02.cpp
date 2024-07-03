#include <iostream>
#include <fstream>
using namespace std;

void main()
{
	// C++스타일
	
	//ifstream => 읽을때 (Read)
	//ofstream => 쓸때 (Write)

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
		cin >> 변수;  랑 비슷한 형태 */
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