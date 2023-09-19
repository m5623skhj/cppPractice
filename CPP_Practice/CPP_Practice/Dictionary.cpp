#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;

void MakeGraph(const vector<string>& words)
{
	graph = vector<vector<int>>(26, vector<int>(26, 0));

	for (int i = 1; i < words.size(); ++i)
	{
		int j = i - 1;
		int len = (int)min(words[i].size(), words[j].size());

		for (int k = 0; k < len; ++k)
		{
			if (words[i][k] != words[j][k])
			{
				int a = words[i][k] - 'a';
				int b = words[j][k] - 'a';
				graph[b][a] = 1;

				break;
			}
		}
	}
}

vector<int> seen, order;

void DFS(int here)
{
	seen[here] = 1;
	for (int there = 0; there < graph.size(); ++there)
	{
		if (graph[here][there] && seen[there] == false)
		{
			DFS(there);
		}

		order.push_back(here);
	}
}

vector<int> TopologicalSort()
{
	int n = (int)graph.size();
	seen = vector<int>(n, 0);
	order.clear();

	for (int i = 0; i < n; ++i)
	{
		if (seen[i] == false)
		{
			DFS(i);
		}
	}

	reverse(order.begin(), order.end());

	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (graph[order[j]][order[i]])
			{
				return vector<int>();
			}
		}
	}

	return order;
}

int main()
{
	return 0;
}