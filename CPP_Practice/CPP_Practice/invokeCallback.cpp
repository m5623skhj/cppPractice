#include <atomic>
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;
using namespace std::literals;

auto func = [](stop_token token)
{
	atomic<int> counter{0};
	auto threadId = this_thread::get_id();
	stop_callback callBack(token, [&counter, threadId]
	{
		cout << "Thread id : " << threadId << " counter : " << counter << endl;
	});

	while (counter < 10)
	{
		this_thread::sleep_for(0.2s);
		++counter;
	}
};

int main()
{
	vector<jthread> threads(10);
	for (auto& thread : threads)
	{
		thread = jthread(func);
	}

	this_thread::sleep_for(0.5s);

	for (auto& thread : threads)
	{
		thread.request_stop();
	}

	return 0;
}