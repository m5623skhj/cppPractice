#include "AlgorithmBase.h"

int* nowArray = nullptr;
int* checkArray = nullptr;

void Add(char c, int& checkSeceret)
{
	switch (c)
	{
	case 'A' :
		++nowArray[0];
		if (nowArray[0] == checkArray[0])
		{
			++checkSeceret;
		}
		break;
	case 'C':
		++nowArray[1];
		if (nowArray[1] == checkArray[1])
		{
			++checkSeceret;
		}
		break;
	case 'G':
		++nowArray[2];
		if (nowArray[2] == checkArray[2])
		{
			++checkSeceret;
		}
		break;
	case 'T':
		++nowArray[3];
		if (nowArray[3] == checkArray[3])
		{
			++checkSeceret;
		}
		break;
	}
}

void Remove(char c, int& checkSeceret)
{
	switch (c)
	{
	case 'A':
		if (nowArray[0] == checkArray[0])
		{
			--checkSeceret;
		}
		--nowArray[0];
		break;
	case 'C':
		if (nowArray[1] == checkArray[1])
		{
			--checkSeceret;
		}
		--nowArray[1];
		break;
	case 'G':
		if (nowArray[2] == checkArray[2])
		{
			--checkSeceret;
		}
		--nowArray[2];
		break;
	case 'T':
		if (nowArray[3] == checkArray[3])
		{
			--checkSeceret;
		}
		--nowArray[3];
		break;
	}
}

int main()
{
	IOSyncOff();

	int checkSize = 4;
	int checkSeceret = 0;
	nowArray = new int[checkSize];
	checkArray = new int[checkSize];

	int stringSize, subStringSize;
	string stringItem;
	cin >> stringSize >> subStringSize >> stringItem;

	for (int i = 0; i < checkSize; ++i)
	{
		nowArray[i] = 0;
	}

	int result = 0;
	for (int i = 0; i < checkSize; ++i)
	{
		cin >> checkArray[i];
		if (checkArray[i] == 0)
		{
			++checkSeceret;
		}
	}
	for (int i = 0; i < subStringSize; ++i)
	{
		Add(stringItem[i], checkSeceret);
	}

	if (checkSeceret == checkSize)
	{
		++result;
	}

	for (int i = subStringSize; i < stringSize; ++i)
	{
		int j = i - subStringSize;

		Add(stringItem[i], checkSeceret);
		Remove(stringItem[j], checkSeceret);
		if (checkSeceret == checkSize)
		{
			++result;
		}
	}
	cout << endl << result << endl << endl;

	return 0;
}