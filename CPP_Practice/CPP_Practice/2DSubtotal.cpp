#include <iostream>
#include <vector>

__forceinline void CalculateSubtotal2D(std::vector<std::vector<int>>& outItems, int x, int y, int originValueFromArray)
{
	outItems[x][y] = outItems[x][y - 1] + outItems[x - 1][y] - outItems[x - 1][y - 1] + originValueFromArray;
}

__forceinline int AnswerSubtotal2D(const std::vector<std::vector<int>>& items, int x1, int y1, int x2, int y2)
{
	return items[x2][y2] - items[x1 - 1][y2] - items[x2][y1 - 1] + items[x1 - 1][y1 - 1];
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::vector<std::vector<int>> array2D;
	std::vector<std::vector<int>> subtotalArray2D;

	int arraySize;

	std::cin >> arraySize;

	array2D.reserve(arraySize + 1);
	subtotalArray2D.reserve(arraySize + 1);
	for (int i = 0; i < arraySize; ++i)
	{
		for (int j = 0; j < arraySize; ++j)
		{
			array2D[i][j] = i + j;
			subtotalArray2D[i][j] = 0;
		}
	}

	for (int i = 1; i < arraySize; ++i)
	{
		for (int j = 1; j < arraySize; ++j)
		{
			CalculateSubtotal2D(subtotalArray2D, i, j, array2D[i][j]);
		}
	}

	int x1, x2, y1, y2;
	std::cin >> x1 >> x2 >> y1 >> y2;
	std::cout << AnswerSubtotal2D(subtotalArray2D, x1, y1, x2, y2) << std::endl;

	return 0;
}