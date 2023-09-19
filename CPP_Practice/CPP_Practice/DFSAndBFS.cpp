#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

#define CHECK_SIZE 10

vector<int> graph[CHECK_SIZE];
bool check[CHECK_SIZE];

void DFS(int start)
{
    stack<int> s;
    s.push(start);
	check[start] = true;
    cout << start << " ";

    while (s.empty() == false)
    {
        int top = s.top();
        s.pop();

        for (int i = 0; i < graph[top].size(); ++i)
        {
            int next = graph[top][i];
            if (check[next] == true)
            {
                continue;
            }

            cout << next << " ";
            check[next] = true;
            s.push(top);
            s.push(next);
            break;
        }
    }
}

void BFS(int start)
{
    queue<int> q;
    q.push(start);
    check[start] = true;

    while (q.empty() == false)
    {
        int front = q.front();
        q.pop();
        cout << front << " ";

        for (int i = 0; i < graph[front].size(); ++i)
        {
            int nextVisitTarget = graph[front][i];
            if (check[nextVisitTarget] == true)
            {
                continue;
            }

            q.push(nextVisitTarget);
            check[nextVisitTarget] = true;
        }
    }
}

namespace DFS_Recursive
{
    vector<vector<int>> _graph;
    vector<bool> visited;

    void DFS_Recursive(int here)
    {
        visited[here] = true;

        for (int i = 0; i < _graph[here].size(); ++i)
        {
            int there = _graph[here][i];
            if (visited[there] == false)
            {
                DFS_Recursive(there);
            }
        }
    }

    void DFSAll()
    {
        visited = vector<bool>(_graph.size(), false);
        for (int i = 0; i < _graph.size(); ++i)
        {
            if (visited[i] == false)
            {
                DFS_Recursive(i);
            }
        }
    }
}

int main()
{
    return 0;
}