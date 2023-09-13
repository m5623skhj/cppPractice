#include "Headers.h"
#include <vector>

template<typename T, int& SZ>
class Arr
{
public:
	Arr() : elements(SZ)
	{
	}

	void Print() const
	{
		for (int i = 0; i < SZ; ++i)
		{
			cout << elements[i] << ' ';
		}

		cout << endl;
	}

private:
	vector<T> elements;
};

int globalSize = 10;

int main()
{
	//Arr<int&, globalSize> y;

	Arr<int, globalSize> x;
	x.Print();
	globalSize += 100;
	//x.Print();

	return 0;
}