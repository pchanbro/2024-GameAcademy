#include "pch.h"
#include "Board.h"

void Board::Init(int size)
{
	_size = size;
	for (int y = 0; y < _size; y++)
	{
		vector<TileType> lines;
		for (int x = 0; x < _size; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
			{
				lines.push_back(TileType::WALL);
			}
			else
			{
				lines.push_back(TileType::EMPTY);
			}
		}
		_tiles.push_back(lines);
	}


	for (int y = 0; y < _size; y++)
	{
		for (int x = 0; x < _size; x++)
		{
			//초록색 지점 인지 확인
			if (x % 2 == 0 || y % 2 == 0)
			{
				continue;
			}

			//목표지점인지 확인
			if (y == _size - 2 && x == _size - 2)
			{
				continue;
			}

			//하단에 도달했는지 확인
			if (y == _size - 2)
			{
				_tiles[y][x + 1] = TileType::EMPTY;
				continue;
			}

			//우측에 도달했는지 확인
			if (x == _size - 2)
			{
				_tiles[y + 1][x] = TileType::EMPTY;
				continue;
			}

			int randValue = rand() % 2;
			if (randValue == 0)
			{
				_tiles[y][x + 1] = TileType::EMPTY;
			}
			else if (randValue == 1)
			{
				_tiles[y + 1][x] = TileType::EMPTY;
			}
		}
	}

	//미로 생성

}
void Board::Render()
{
	for (int y = 0; y < _size; y++)
	{
		for (int x = 0; x < _size; x++)
		{
			switch (_tiles[y][x])
			{
			case TileType::EMPTY:
				ConsoleHelper::SetCursorColor(ConsoleColor::GREEN, ConsoleColor::BLACK);
				cout << TILE;
				break;
			case TileType::WALL:
				ConsoleHelper::SetCursorColor(ConsoleColor::RED, ConsoleColor::BLACK);
				cout << TILE;
				break;
			}
			 
		}
		cout << endl;
	}
}