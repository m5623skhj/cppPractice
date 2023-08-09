#include <iostream>
#include <barrier>
#include <mutex>
#include <string>
#include <thread>

using namespace std;

barrier workDone(6);
mutex mu;

void SynchronizedOut(const string& s)
{
	lock_guard<mutex> lock(mu);
	cout << s;
}

class FullTimeWorker
{
public:
	FullTimeWorker(string n)
		: name(n)
	{
	}

	void operator() ()
	{
		SynchronizedOut(name + ": " + "Morning work done\n");
		workDone.arrive_and_wait();

		SynchronizedOut(name + ": " + "After work done\n");
		workDone.arrive_and_wait();
	}

private:
	string name;
};

class PartTimeWorker
{
public:
	PartTimeWorker(string n)
		: name(n)
	{
	}

	void operator() ()
	{
		SynchronizedOut(name + ": " + "Morning work done\n");
		workDone.arrive_and_drop();
	}

private:
	string name;
};

int main()
{
	cout << "Start work" << endl;

	FullTimeWorker full_a(" a");
	thread aThread(full_a);

	FullTimeWorker full_b(" b");
	thread bThread(full_b);

	FullTimeWorker full_c(" c");
	thread cThread(full_c);

	PartTimeWorker part_d(" d");
	thread dThread(part_d);

	PartTimeWorker part_e(" e");
	thread eThread(part_e);

	PartTimeWorker part_f(" f");
	thread fThread(part_f);

	aThread.join();
	bThread.join();
	cThread.join();
	dThread.join();
	eThread.join();
	fThread.join();

	return 0;
}