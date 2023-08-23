#include "Headers.h"
#include <syncstream>

mutex mu;

class Worker
{
public:
	Worker(string str) 
		: name(str)
	{}

	void operator() ()
	{
		for (int i = 1; i <= 3; ++i)
		{
			this_thread::sleep_for(chrono::milliseconds(200));
			osyncstream(cout) << name << " : Worker " << i << " done" << endl;
		}
	}

private:
	string name;
};

int main()
{
	cout << "start" << endl;

	thread a = thread(Worker("a"));
	thread b = thread(Worker("b"));
	thread c = thread(Worker("c"));
	thread d = thread(Worker("d"));
	thread e = thread(Worker("e"));
	thread f = thread(Worker("f"));

	a.join();
	b.join();
	c.join();
	d.join();
	e.join();
	f.join();

	cout << "end" << endl;

	return 0;
}