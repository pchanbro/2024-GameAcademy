#include <iostream>

using namespace std;

void main()
{
	// file write

	// 2���� ���
	// C��Ÿ��
	// C++��Ÿ��

	// C��Ÿ��

	//fopen_s
	//fread, fwrite
	//fclose

	if (false)
	{	
		FILE* file = nullptr;
		// wb => write ���·� �Ұǵ�, binary�� ���ڴ�.
		// wt => write ���·� �Ұǵ�, text�� ���ڴ�.
		// rb => read ���·� �Ұǵ�, binary�� �аڴ�.
		// rt => read ���·� �Ұǵ�, text�� �аڴ�.

		fopen_s(&file, "test.txt", "wt");

		if (file == nullptr)
		{
			cout << "file nullptr ����" << endl;
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

	// �о���� ���
	if (true)
	{
		FILE* file = nullptr;
		fopen_s(&file, "test.txt", "rb");
		
		if (file == nullptr)
		{
			cout << "file nullptr ����" << endl;
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