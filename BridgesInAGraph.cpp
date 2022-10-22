#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>

void bridgeDFS(int i, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis,
         vector<int> &parent, vector<int> &disc,
         vector<int> &low, int &timer, vector<vector<int>> &res)
{
    vis[i] = true;
    disc[i] = timer;
    low[i] = timer;

    for (auto it : adj[i])
    {
        if (!vis[it])
        {
            parent[it] = i;
            timer++;
            bridgeDFS(it, adj, vis, parent, disc, low, timer, res);
            low[i] = min(low[i], low[it]);
            if (low[it] > disc[i])
            {
                vector<int> ans;
                ans.push_back(i);
                ans.push_back(it);
                res.push_back(ans);
            }
        }
        else if (vis[it] && it != parent[i])
        {
            low[i] = min(low[i], disc[it]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    // Write your code here
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < e; i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    unordered_map<int, bool> vis;
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    vector<int> parent(v, -1);
    int timer = 0;
    vector<vector<int>> res;

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            bridgeDFS(i, adj, vis, parent, disc, low, timer, res);
        }
    }

    return res;
}