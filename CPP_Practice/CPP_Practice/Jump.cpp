#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> board;
vector<vector<int>> cache;

int Jump(int x, int y)
{
	if (y >= n || x >= n)
	{
		return 0;
	}

	if (y == n - 1 && x == n - 1)
	{
		return 1;
	}

	int& retval = cache[y][x];
	if (retval != -1)
	{
		return retval;
	}

	int jump = board[y][x];
	return retval = (Jump(x, y + jump) || Jump(x + jump, y));
}

int main()
{
	// make case to board;

	return 0;
}