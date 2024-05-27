#include <iostream>

using namespace std;

void main()
{
	// file write

	// 2가지 방법
	// C스타일
	// C++스타일

	// C스타일

	//fopen_s
	//fread, fwrite
	//fclose

	if (false)
	{	
		FILE* file = nullptr;
		// wb => write 형태로 할건데, binary로 쓰겠다.
		// wt => write 형태로 할건데, text로 쓰겠다.
		// rb => read 형태로 할건데, binary로 읽겠다.
		// rt => read 형태로 할건데, text로 읽겠다.

		fopen_s(&file, "test.txt", "wt");

		if (file == nullptr)
		{
			cout << "file nullptr 에러" << endl;
			return;
		}

		int a = 3;
		fwrite(&a, sizeof(a), 1, file);
		fwrite(&a, sizeof(a), 1, file);
		fwrite(&a, sizeof(a), 1, file);
		fwrite(&a, sizeof(a), 1, file);
		fwrite(&a, sizeof(a), 1, file);
		fwrite(&a, sizeof(a), 1, file);

		fclose(file);
	}

	// 읽어오는 방법
	if (true)
	{
		FILE* file = nullptr;
		fopen_s(&file, "test.txt", "rb");
		
		if (file == nullptr)
		{
			cout << "file nullptr 에러" << endl;
			return;
		}

		int value;

		fread(&value, sizeof(value), 1, file);
		fread(&value, sizeof(value), 1, file);
		fread(&value, sizeof(value), 1, file);
		fread(&value, sizeof(value), 1, file);
		fread(&value, sizeof(value), 1, file);
		fread(&value, sizeof(value), 1, file);

		printf("size : %d\n", value);
	}
}