#include <iostream>
#include <mutex>
#include <latch>
#include <thread>

using namespace std;

latch workDone(6);
latch goHome(1);

mutex mu;

void SynchronizedOut(const string& s)
{
	lock_guard<mutex> lock(mu);
	cout << s;
}

class Worker
{
public:
	Worker(string n)
		: name(n)
	{
	}

	void operator() ()
	{
		SynchronizedOut(name + ": " + "Work done\n");
		workDone.count_down();

		goHome.wait();
		SynchronizedOut(name + ": " + "Good bye\n");
	}

private:
	string name;
};

int main()
{
	cout << "Start work" << endl;

	Worker a(" a");
	thread aThread(a);

	Worker b(" b");
	thread bThread(b);

	Worker c(" c");
	thread cThread(c);

	Worker d(" d");
	thread dThread(d);

	Worker e(" e");
	thread eThread(e);

	Worker f(" f");
	thread fThread(f);

	workDone.wait();

	goHome.count_down();

	aThread.join();
	bThread.join();
	cThread.join();
	dThread.join();
	eThread.join();
	fThread.join();

	return 0;
}