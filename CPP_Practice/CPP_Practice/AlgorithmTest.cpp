#include "AlgorithmTest.h"
#include <iostream>
#include <deque>

void FindMinimum1()
{
	using namespace std;
	using Node = pair<int, int>;

	std::deque<Node> findDeque;
	int N, L;
	std::cin >> N >> L;

	int now;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> now;

		while (findDeque.size() && findDeque.back().first > now)
		{
			findDeque.pop_back();
		}
		findDeque.push_back(Node(now, i));

		if (findDeque.front().second <= i - L)
		{
			findDeque.pop_front();
		}

		std::cout << findDeque.front().first << ' ';
	}
}
