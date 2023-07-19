#include <iostream>

using namespace std;

struct BitField
{
	int i : 3 = 1;
	int j : 4 = 2;
	int k : 5 = 3;
	int l : 6 = 4;
	int m : 7 = 5;
	int n : 7 = 6;
};

// 3 + 4 + 5 + 6 + 7 + 8 = 33이므로, int의 크기 범위를 넘어가기 때문에, 8byte가 된듯
struct BitField2
{
	int i : 3 = 1;
	int j : 4 = 2;
	int k : 5 = 3;
	int l : 6 = 4;
	int m : 7 = 5;
	int n : 8 = 6;
};

struct BitField3
{
	_int64 i : 3 = 1;
	_int64 j : 4 = 2;
	_int64 k : 5 = 3;
	_int64 l : 6 = 4;
	_int64 m : 7 = 5;
	_int64 n : 8 = 6;
};

int main()
{
	BitField b;
	cout << sizeof(b) << endl;
	cout << b.i << " " << b.j << " " << b.k << " " << b.l << " " << b.m << " " << b.n << endl;

	BitField2 b2;
	cout << sizeof(b2) << endl;

	BitField3 b3;
	cout << sizeof(b3) << endl;

	return 0;
}