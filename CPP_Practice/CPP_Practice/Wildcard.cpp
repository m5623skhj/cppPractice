#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> cache;
string g_w, g_s;

bool Match(int w, int s)
{
	int& retval = cache[w][s];
	if (retval != -1)
	{
		return retval;
	}

	while (s < g_s.size() && w < g_w.size() && g_w[w] == '?' || g_w[w] == g_s[s])
	{
		return retval = Match(w + 1, s + 1);
	}

	if (w == g_w.size())
	{
		return retval = (s == g_s.size());
	}

	if (g_w[w] == '*')
	{
		if (Match(w + 1, s) || (s < g_s.size() && Match(w, s + 1)))
		{
			return retval = 1;
		}
	}

	return retval = 0;
}

int main()
{


	return 0;
}