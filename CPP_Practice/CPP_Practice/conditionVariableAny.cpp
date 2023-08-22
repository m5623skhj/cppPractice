#include <condition_variable>
#include <thread>
#include <iostream>
#include <chrono>
#include <mutex>
#include <thread>

using namespace std;
using namespace std::literals;

mutex mu;
condition_variable_any conditionVariable;

bool dataIsReady = false;

void Receiver(stop_token stopToken)
{
	cout << "Waiting.." << endl;

	unique_lock<mutex> lock(mu);
	bool retval = conditionVariable.wait(lock, stopToken, []
		{
			return dataIsReady;
		});

	if (retval == true)
	{
		cout << "Notification received : " << endl;
	}
	else
	{
		cout << "Stop request received" << endl;
	}
}

void Sender()
{
	this_thread::sleep_for(5ms);
	{
		lock_guard<mutex> lock(mu);
		dataIsReady = true;
		cout << "Send notification" << endl;
	}

	conditionVariable.notify_one();
}

int main()
{
	jthread thread1(Receiver);
	jthread thread2(Sender);

	thread1.request_stop();

	thread1.join();
	thread2.join();

	return 0;
}