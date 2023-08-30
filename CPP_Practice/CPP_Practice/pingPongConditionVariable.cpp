#include "Headers.h"

bool isDataReady = false;

mutex mu;
condition_variable condition1;
condition_variable condition2;

atomic<int> counter = 0;
constexpr int countLimit = 1000000;

void Ping()
{
	while (counter <= countLimit)
	{
		{
			unique_lock<mutex> lock(mu);
			condition1.wait(lock, [] { return isDataReady == false; });
			isDataReady = true;
		}

		++counter;
		condition2.notify_one();
	}
}

void Pong()
{

	while (counter <= countLimit)
	{
		{
			unique_lock<mutex> lock(mu);
			condition2.wait(lock, [] { return isDataReady == true; });
			isDataReady = false;
		}

		condition1.notify_one();
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