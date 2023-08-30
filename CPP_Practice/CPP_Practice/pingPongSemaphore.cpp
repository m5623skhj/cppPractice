#include "Headers.h"
#include <semaphore>

counting_semaphore<1> signalPing(0);
counting_semaphore<1> signalPong(0);

atomic<int> counter = 0;
constexpr int countLimit = 1000000;

void Ping()
{
	while (counter <= countLimit)
	{
		signalPing.acquire();
		++counter;
		signalPong.release();
	}
}

void Pong()
{

	while (counter <= countLimit)
	{
		signalPong.acquire();
		signalPing.release();
	}
}

int main()
{
	auto start = chrono::system_clock::now();

	signalPing.release();

	thread t1(Ping);
	thread t2(Pong);

	t1.join();
	t2.join();

	chrono::duration<double> duration = chrono::system_clock::now() - start;
	cout << "Duration : " << duration.count() << "s" << endl;

	return 0;
}