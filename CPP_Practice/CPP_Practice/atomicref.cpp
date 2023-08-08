#include <atomic>
#include <iostream>
#include <random>
#include <thread>
#include <vector>

using namespace std;

struct ExpensiveToCopy
{
	int counter{};
};

int GetRandom(int begin, int end)
{
	random_device seed;
	mt19937 engine(seed());
	uniform_int_distribution<> uniformDist(begin, end);

	return uniformDist(engine);
}

void Count(ExpensiveToCopy& exp)
{
	vector<thread> v;
	// exp.counter�� ���纻�� ����� counter�� ����
	// ������ exp�� ���� ������� ����
	//atomic<int> counter{exp.counter};
	atomic_ref<int> counter{exp.counter};

	for (int n = 0; n < 10; ++n)
	{
		v.emplace_back([&counter]
			{
				auto randomNumber = GetRandom(100, 200);
				for (int i = 0; i < randomNumber; ++i)
				{
					++counter;
				}
			});
	}

	for (auto& t : v)
	{
		t.join();
	}
}

int main()
{
	ExpensiveToCopy exp;
	Count(exp);
	cout << exp.counter << endl;

	return 0;
}