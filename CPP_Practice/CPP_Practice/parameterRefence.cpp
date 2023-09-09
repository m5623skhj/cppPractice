#include "Headers.h"

template<typename T>
void ParameterIsReference(T)
{
	cout << "T is reference type : " << is_reference_v<T> << endl;
}

int main()
{
	cout << boolalpha;

	int i;
	int& r = i;
	ParameterIsReference(i);
	ParameterIsReference(r);
	ParameterIsReference<int&>(i);
	ParameterIsReference<int&>(r);
}