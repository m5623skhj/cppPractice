#include "foreach.hpp"
#include <iostream>
#include <vector>

using namespace std;

void func(int i)
{
	cout << "func() called for : " << i << endl;
}

class Functor
{
public:
	void operator() (int i) const
	{
		cout << "Functor::op() called for: " << i << endl;
	}
};

int main()
{
	vector<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19 };
	foreach(primes.begin(), primes.end(), func);
	foreach(primes.begin(), primes.end(), &func);
	foreach(primes.begin(), primes.end(), Functor());
	foreach(primes.begin(), primes.end(), 
		[](int i)
		{
			cout << "lambda called for : " << i << endl;
		});

	return 0;
}