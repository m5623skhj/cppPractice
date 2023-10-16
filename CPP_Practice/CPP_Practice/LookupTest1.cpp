#include <iostream>
#include "LookupTest1.h"

extern int count;

int lookup(int count)
{
	if (count < 0)
	{
		int count = 1;
		std::cout << lookup(count) << std::endl;
	}

	return count + ::count;
}

int main()
{
	int i = -1;

	std::cout << lookup(i) << std::endl;

	return 0;
}