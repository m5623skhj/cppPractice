#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

vector<int> myVec{};
atomic_flag flag{};

void PrepareWork()
{
	myVec.insert(myVec.end(), { 0, 1, 0, 3 });
	cout << "Sender: Data prepared." << endl;
	flag.test_and_set();
	flag.notify_one();
}

void CompleteWork()
{
	cout << "Waiter: Waiting for data." << endl;
	flag.wait(false);
	myVec[2] = 2;
	cout << "Waiter: Complete the work." << endl;
	for (auto i : myVec)
	{
		cout << 1 << " ";
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