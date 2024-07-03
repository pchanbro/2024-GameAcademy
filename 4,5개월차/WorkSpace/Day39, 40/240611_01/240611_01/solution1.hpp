// ���� ������ �����ͼ� Ǯ ����
// .hpp�� ������ �����ϰ�
// �Ӽ� - �׸� ������ C/C++ ������� Ȯ���ϱ�

#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

// DFS, BFS
// �����ڵ�

// DFS �����ڵ�
// 1. ���� ���� v(visit or vertex)�� �����Ͽ� �湮
// while(stack.empty() == false)
//      2. ���� v�� ������ �����߿���
//       �湮���� ���� ���� w�� ������ 
//       ���� v�� stack�� push�ϰ� w�� �湮
//       �湮���� ���� ������ ������ ������ pop�ؼ� ���� ������ v�� �Ѵ�.


// start �������� �����ϴ� ��� �� �� �ִ� ����� ���� �� �� ����.
void dfs_stack(int n, vector<vector<int>> computers, int start, vector<int>& visited)
{
    stack<int> s;
    s.push(start);

    while (false == s.empty())
    {
        int current = s.top();
        s.pop();
        // �湮�ߴ� üũ
        visited[current] = 1;

        // 1. current���� �� �� �ִ� ������ üũ
        for (int i = 0; i < n; i++)
        {
            if (computers[current][i] == 1 && visited[i] == 0)
            {
                // ���� �켱üũ
                s.push(i);
            }
        }

    }
}

// dfs�� ��ͷε� ����� �� �ִ�.
// ����Լ��� �Լ���(�޸� 4Byte ����)�� �ϱ� ������ �޸����� �κп����� ��͸� ���� �ʴ°� ���� �� ����.
// ������ ����Լ��� �������� ����.
void dfs_recursive(int n, vector<vector<int>> computers, int start, vector<int>& visited)
{
    visited[start] = 1;

    for (int i = 0; i < n; i++)
    {
        if (computers[start][i] == 1 && visited[i] == 0)
        {
            dfs_recursive(n, computers, i, visited);
            // ��͸� �� Ƚ����ŭ �޸� ����(�Լ��� ������ ���� ����ؼ� ����ϴϱ�)
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
        // �湮�ߴ� üũ
        visited[current] = 1;

        // 1. current���� �� �� �ִ� ������ üũ
        for (int i = 0; i < n; i++)
        {
            if (computers[current][i] == 1 && visited[i] == 0)
            {
                // ���� �켱üũ
                s.push(i);
            }
        }

    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    // dfs�� Ȱ���ؼ�
    // �� �������� ������ �ȵǾ������� ������ ã�Բ�.

    /*vector<int> visited = {};
    for (int i = 0; i < n; i++)
    {
        visited.push_back(0);
    }*/
    // �� �ڵ带 ���ٷ� ���̸�
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