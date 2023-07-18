#include <iostream>
#include <string>
#include <vector>
#include <concepts>
#include <deque>
#include <cmath>
#include <memory>
#include <set>

using namespace std;

auto sumInt = [](int fir, int sec) {return fir + sec; };
auto sumGen = [](auto fir, auto sec) {return fir + sec; };
auto sumDec = [](auto fir, decltype(fir) sec) { return fir + sec; };
// ÅÛÇÃ¸´ ¶÷´Ù
auto sumTem = []<typename T>(T fir, T sec) { return fir + sec; };

auto lambdaGeneric = [](const auto& container) { return container.size(); };
auto lambdaVector = []<typename T>(const vector<T>&vec) { return vec.size(); };
auto lambdaVectorIntegral = []<integral T>(const vector<T>&vec) { return vec.size(); };

template <typename Cont>
void printContainer(const Cont& cont)
{
	for (const auto& c : cont)
	{
		cout << c << " ";
	}

	cout << endl;
}

int main()
{
	cout << "sumInt(2000, 11): " << sumInt(2000, 11) << endl;
	cout << "sumGen(2000, 11): " << sumGen(2000, 11) << endl;
	cout << "sumDec(2000, 11): " << sumDec(2000, 11) << endl;
	cout << "sumTem(2000, 11): " << sumTem(2000, 11) << endl;

	cout << endl;

	string hello = "Hello ";
	string world = "world";

	cout << "sumGen(hello, world): " << sumGen(hello, world) << endl;
	cout << "sumDec(hello, world): " << sumDec(hello, world) << endl;
	cout << "sumTem(hello, world): " << sumTem(hello, world) << endl;

	cout << endl;

	cout << "sumInt(true, 2010): " << sumInt(true, 2010) << endl;
	cout << "sumGen(true, 2010): " << sumGen(true, 2010) << endl;
	cout << "sumDec(true, 2010): " << sumDec(true, 2010) << endl;
	//cout << "sumTem(true, 2010): " << sumTem(true, 2010) << endl;

	cout << endl;
	cout << endl;
	cout << endl;

	set<string> set1 = { "sco", "Bja", "Her", "Dave", "mic" };
	printContainer(set1);

	using Descreasing = set < string, decltype([](const auto& l, const auto& r)
		{
			return l > r;
		})>;
	Descreasing set2 = { "sco", "Bja", "Her", "Dave", "mic" };
	printContainer(set2);

	using Length = set < string, decltype([](const auto& l, const auto& r)
		{
			return l.size() < r.size();
		})>;
	Length set3 = { "sco", "Bja", "Her", "Dave", "mic" };
	printContainer(set3);

	set<int> set4 = { -10, 5, 3, 100, 0, -25 };
	printContainer(set4);

	using Abs = set<int, decltype([](const auto& l, const auto& r)
		{
			return abs(l) < abs(r);
		}) > ;
	Abs set5 = { -10, 5, 3, 100, 0, -25 };
	printContainer(set5);

	return 0;
}
