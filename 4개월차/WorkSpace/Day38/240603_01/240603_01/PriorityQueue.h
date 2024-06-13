#pragma once
#include <vector> // 우선순위 큐는 노드를 추가, 제거 할 때마다 길이가 계속 변하기 때문에 벡터를 사용한다.
#include <assert.h>
using namespace std;

template <typename T>
class PriorityQueue
{
private:
	vector<T> _arr;
public:
	T& Peek()
	{
		assert(0 < _arr.size());
		return _arr[0];
	}

	bool Empty()
	{
		return _arr.size() == 0;
	}

	void Pop()
	{
		assert(0 < _arr.size());
		::swap(_arr[_arr.size() - 1], _arr[0]);
		_arr.pop_back();

		int index = 0;

		while (true)
		{
			if (_arr.size() == 0)
			{
				break;
			}
			if (_arr.size() - 1 < index * 2 + 1)
			{
				// 왼쪽 자식 인덱스가 배열사이즈보다 더 커져버리면 끝.
				break;
			}

			T& currentNode = _arr[index];
			T& leftNode = _arr[index * 2 + 1];
			T rightNode = _arr[index];
			bool rightNodeExist = false;

			if (index * 2 + 2 <= _arr.size() - 1)
			{
				rightNode = _arr[index * 2 + 2];
				rightNodeExist = true;
			}

			if (rightNodeExist)
			{
				// 오른쪽 자식이 왼쪽자식보다 더 크면 오른쪽 자식과 비교
				if (leftNode < rightNode)
				{
					//자식이 더 클때
					if (currentNode < rightNode)
					{
						::swap(_arr[index * 2 + 2], currentNode);
						index = index * 2 + 2;
					}
					else
					{
						break;
					}
				}
				// 왼쪽 자식이 오른쪽자식보다 더 크면 왼쪽 자식과 비교
				else if (rightNode < leftNode)
				{
					//자식이 더 클때
					if (currentNode < leftNode)
					{
						::swap(leftNode, currentNode);
						index = index * 2 + 1;
					}
					else
					{
						break;
					}
				}
				else
				{
					break;
				}
			}
			else
			{
				if (currentNode < leftNode)
				{
					::swap(leftNode, currentNode);
					index = index * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}
	}
	void Push(T data)
	{
		_arr.push_back(data);

		int index = _arr.size() - 1;
		while (true)
		{
			if (index == 0) break;

			// 비교
			// 부모노드와 현재 노드를 비교
			T parentNode = _arr[(index - 1) / 2];
			T currentNode = _arr[index];

			if (parentNode < currentNode)
			{
				::swap(parentNode, currentNode);
				/*T temp = _arr[(index - 1) / 2];
				_arr[(index - 1) / 2] = currentNode;
				_arr[index] = temp;*/

				index = (index - 1) / 2;
			}
			else
			{
				break;
			}
		}
	}
};

