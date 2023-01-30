#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

unordered_map<int, vector<int>> adj;

bool bfs(int s, int t)
{
    queue<int> q;
    unordered_map<int, int> vis;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        if (u == t)
            return true;
        for (auto x : adj[u])
        {
            if (!vis[x])
            {
                q.push(x);
            }
        }
    }
    return false;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int e, n;
    cin >> e;
    for (int i = 0; i < e; ++i)
    {
        int t;
        cin >> t;
        adj[t] = vector<int>();
    }
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[b - 1].push_back(a - 1);
    }

    int x, y;
    cin >> x >> y;
    set<int> ans;
    for (int z : adj[y - 1])
    {
        if (bfs(z, x - 1)) ans.insert(z + 1);
    }
    if (ans.size() == 0)
        cout << -1 << "\n";
    else
    {
        for (int i : ans)
            cout << i << " ";
    }

    return 0;
}