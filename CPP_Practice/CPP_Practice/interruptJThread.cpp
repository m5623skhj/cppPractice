#include "Headers.h"

int main()
{
	jthread nonInterruptible([] {
		int counter = 0;
		while (counter < 10)
		{
			this_thread::sleep_for(0.2s);
			cerr << "nonInterruptible : " << counter << endl;
			++counter;
		}
		});

	jthread interruptible([](stop_token stopToken) {
		int counter = 0;
		while (counter < 10)
		{
			this_thread::sleep_for(0.2s);
			if (stopToken.stop_requested() == true)
			{
				return;
			}

			cerr << "nonInterruptible : " << counter << endl;
			++counter;
		}
		});

	this_thread::sleep_for(1s);
	cerr << "main thread interrupts both jthreads" << endl;
	nonInterruptible.request_stop();
	interruptible.request_stop();

	return 0;
}