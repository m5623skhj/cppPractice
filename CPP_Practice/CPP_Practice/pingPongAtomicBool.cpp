#include "Headers.h"

atomic<bool> atomicBool = false;

atomic<int> counter = 0;
constexpr int countLimit = 1000000;

void Ping()
{
	while (counter <= countLimit)
	{
		atomicBool.wait(true);
		atomicBool.store(true);

		++counter;

		atomicBool.notify_one();
	}
}

void Pong()
{

	while (counter <= countLimit)
	{
		atomicBool.wait(false);
		atomicBool.store(false);
		atomicBool.notify_one();
	}
}

int main()
{
	auto start = chrono::system_clock::now();

	thread t1(Ping);
	thread t2(Pong);

	t1.join();
	t2.join();

	chrono::duration<double> duration = chrono::system_clock::now() - start;
	cout << "Duration : " << duration.count() << "s" << endl;

	return 0;
}