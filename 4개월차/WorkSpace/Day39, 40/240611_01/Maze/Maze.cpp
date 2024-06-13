// Maze.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include "Board.h"
#include "Player.h"
int main()
{
    srand(time(NULL));

    ConsoleHelper::ShowConsoleCursor(false);

    Player* player = new Player();

    Board* board = new Board();
    board->Init(25, player);

    player->Init(board);


    __int64 lastTick = ::GetTickCount64();
    __int64 sumTick = 0;
    while (true)
    {
        // 이 부분이 없으면 board->Render(); 로 그림을 빡세게 그려서 렉걸림
        const __int64 currentTick = ::GetTickCount64();
        const __int64 deltaTime = currentTick - lastTick;
        lastTick = currentTick;

        sumTick += deltaTime;
        if (100 <= sumTick)
        {
            sumTick = 0;
            player->Update();
            board->Render();
        }

    }

    ConsoleHelper::SetCursorColor(ConsoleColor::BLACK, ConsoleColor::BLACK);
}