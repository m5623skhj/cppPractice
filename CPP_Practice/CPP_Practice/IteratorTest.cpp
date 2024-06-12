#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
	list<int> testList;
	vector<int> testVector;

	for (int i = 0; i < 10; ++i)
	{
		int randomItem = rand();

		testList.push_back(randomItem);
		testVector.push_back(randomItem);
	}

	sort(testVector.begin(), testVector.end());

	// ������ ���� �߻�
	// https://cplusplus.com/reference/iterator/BidirectionalIterator/
	// https://cplusplus.com/reference/list/list/begin/#google_vignette
	// ���� �����ؼ� ���� ���� ��
	//sort(testList.begin(), testList.end());
	testList.sort();

	return 0;
}