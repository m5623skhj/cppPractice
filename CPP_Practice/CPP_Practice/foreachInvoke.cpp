#include <iostream>
#include <vector>
#include <string>
#include "foreachInvoke.hpp"

using namespace std;

class MyClass
{
public:
	void memfunc(int i) const
	{
		cout << "MyClass::memfunc() called for : " << i << endl;
	}
};

int main()
{
	vector<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19 };

	foreach(primes.begin(), primes.end(),
		[](string const& prefix, int i) {
			cout << prefix << i << endl;
		}, " - value : ");

	MyClass obj;
	foreach(primes.begin(), primes.end(), &MyClass::memfunc, obj);

	return 0;
}