#include <iostream>
#include <ranges>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main()
{
	vector<int> num = { 1, 2, 3, 4, 5, 6 };

	auto result = num 
	| views::filter([](int n) { return n % 2 == 0; })
	| views::transform([](int n) {return n * 2; });

	for (const auto& item : result)
	{
		cout << item << " ";
	}
	cout << endl;

	vector<int> vec{-3, 5, 0, 100, 4};
	// sort(vec.begin(), vec.end());
	// =>
	ranges::sort(vec);
	for (const auto& item : vec)
	{
		cout << item << " ";
	}
	cout << endl;

	// func1 | func2 == func2(func1())
	map<string, int> word = { {"witch", 25}, {"wizard", 33}, {"tale", 45}, {"dog", 4}, {"cat", 34}, {"fish", 23} };
	for (const auto& name : views::keys(word) | views::reverse)
	{
		cout << name << " ";
	}
	cout << endl;



	return 0;
}