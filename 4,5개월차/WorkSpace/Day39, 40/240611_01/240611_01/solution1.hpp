// 코테 문제를 가져와서 풀 때는
// .hpp로 파일을 생성하고
// 속성 - 항목 형식이 C/C++ 헤더인지 확인하기

#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

// DFS, BFS
// 수도코드

// DFS 수도코드
// 1. 시작 정점 v(visit or vertex)를 결정하여 방문
// while(stack.empty() == false)
//      2. 정점 v에 인접한 정점중에서
//       방문하지 않은 정점 w가 있으면 
//       정점 v를 stack에 push하고 w를 방문
//       방문하지 않은 정점이 없으면 스택을 pop해서 받은 정점을 v로 한다.


// start 정점으로 시작하는 모든 갈 수 있는 경우의 수를 알 수 있음.
void dfs_stack(int n, vector<vector<int>> computers, int start, vector<int>& visited)
{
    stack<int> s;
    s.push(start);

    while (false == s.empty())
    {
        int current = s.top();
        s.pop();
        // 방문했다 체크
        visited[current] = 1;

        // 1. current에서 갈 수 있는 정점을 체크
        for (int i = 0; i < n; i++)
        {
            if (computers[current][i] == 1 && visited[i] == 0)
            {
                // 깊이 우선체크
                s.push(i);
            }
        }

    }
}

// dfs는 재귀로도 사용할 수 있다.
// 재귀함수는 함수콜(메모리 4Byte 차지)을 하기 때문에 메모리적인 부분에서는 재귀를 쓰지 않는게 조금 더 좋다.
// 하지만 재귀함수가 가독성이 좋다.
void dfs_recursive(int n, vector<vector<int>> computers, int start, vector<int>& visited)
{
    visited[start] = 1;

    for (int i = 0; i < n; i++)
    {
        if (computers[start][i] == 1 && visited[i] == 0)
        {
            dfs_recursive(n, computers, i, visited);
            // 재귀를 한 횟수만큼 메모리 차지(함수가 끝나기 전에 계속해서 재귀하니까)
        }
    }
}

void bfs_queue(int n, vector<vector<int>> computers, int start, vector<int>& visited)
{
    queue<int> s;
    s.push(start);

    while (false == s.empty())
    {
        int current = s.front();
        s.pop();
        // 방문했다 체크
        visited[current] = 1;

        // 1. current에서 갈 수 있는 정점을 체크
        for (int i = 0; i < n; i++)
        {
            if (computers[current][i] == 1 && visited[i] == 0)
            {
                // 깊이 우선체크
                s.push(i);
            }
        }

    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    // dfs를 활용해서
    // 각 정점마다 연결이 안되어있으면 뭉텅이 찾게끔.

    /*vector<int> visited = {};
    for (int i = 0; i < n; i++)
    {
        visited.push_back(0);
    }*/
    // 위 코드를 한줄로 줄이면
    vector<int> visited(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            ::dfs_recursive(n, computers, i, visited);
            answer++;
        }
    }


    return answer;
}