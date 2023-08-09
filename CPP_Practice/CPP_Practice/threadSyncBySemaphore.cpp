#include <iostream>
#include <semaphore>
#include <thread>
#include <vector>

using namespace std;

vector<int> vec{};
counting_semaphore<1> signal(0);

void PrepareWork()
{
	vec.insert(vec.end(), { 0, 1, 0, 3 });
	cout << "Sender: Data prepared." << endl;
	signal.release();
}

void CompleteWork()
{
	cout << "Waiter: Wating for data" << endl;
	signal.acquire();
	vec[2] = 2;
	cout << "Waiter: Complete the work" << endl;
	for (auto i : vec)
	{
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	thread t1(PrepareWork);
	thread t2(CompleteWork);

	t1.join();
	t2.join();

	return 0;
}