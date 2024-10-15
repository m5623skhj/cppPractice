#include <iostream>

int main()
{
	if (int* intPtr = nullptr)
	{
		std::cout << "Print first test, just init in if expression" << std::endl;
	}

	int tempItem = 0;
	if (int* intPtr = nullptr; tempItem == 0)
	{
		std::cout << "Print second test, Initialization after semicolon within comparison statements and if expressions" << std::endl;
	}

	return 0;
}