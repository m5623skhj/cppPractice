#include <iostream>
#include <thread>
#include <future>

using namespace std;
using namespace std::literals;

void Function_1(stop_token token, const string& str)
{
	this_thread::sleep_for(1s);
	if (token.stop_requested() == true)
	{
		cout << str << "stop requested" << endl;
	}
}

void Function_2(promise<void> prom, stop_token token, const std::string& str)
{
	this_thread::sleep_for(1s);
	stop_callback callBack(token, [&str] 
	{
		cout << str << "stop requested" << endl;
	});
	prom.set_value();
}

int main()
{
	stop_source stopSource;
	stop_token stopToken = stop_token(stopSource.get_token());

	thread thread1 = thread(Function_1, stopToken, "std::thread");
	jthread jthread1 = jthread(Function_1, stopToken, "std::jthread");

	auto future1 = async([stopToken]
		{
			this_thread::sleep_for(1s);
			if (stopToken.stop_requested() == true)
			{
				cout << "async : stop requeted" << endl;
			}
		});

	promise<void> prom;
	auto future2 = prom.get_future();
	thread thread2(Function_2, std::move(prom), stopToken, "std::Promise");

	stopSource.request_stop();

	//thread1.join();
	//thread2.join();

	if (stopToken.stop_requested() == true)
	{
		cout << "main : stop requested" << endl;
	}

	thread1.join();
	thread2.join();

	return 0;
}