#include <iostream>
#include<vector>
#include<queue>

using namespace std;

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    // Write your code here.
    // defing adjacency matrix
    vector<int> adj[n+1];
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    // calculating indegree
    vector<int> indegree(n+1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    int cnt = 0;

    while (!q.empty())
    {
        int n = q.front();
        q.pop();
        cnt++;
        for (auto it : adj[n])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }

    if (cnt == n)
        return 0;
    return 1;
}