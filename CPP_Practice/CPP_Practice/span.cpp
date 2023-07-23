#include <iostream>
#include <span>
#include <vector>

using namespace std;

void PrintMe(const std::span<int>& container)
{
	cout << "Size : " << container.size() << endl;
	for (const auto& item : container)
	{
		cout << item << " ";
	}
	cout << endl;
}

int main()
{
	// 정적 배열도 크기를 잘 출력해줌
	int arr[]{ 1, 2, 3, 4 };
	PrintMe(arr);

	vector vec{ 1, 2, 3, 4, 5 };
	PrintMe(vec);

	span span1{ vec };
	span span2{ vec.data(), vec.size() };

	cout << equal(span1.begin(), span1.end(), span2.begin(), span2.end()) << endl;

	return 0;
}