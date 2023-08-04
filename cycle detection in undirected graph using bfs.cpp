//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool solveBFS(int src, int V, vector<int> adj[], vector<bool> &vis)
    {
        vis[src]=true;
        queue<pair<int,int>> q;
        q.push({src,-1});

        while(!q.empty())
        {
            auto it  = q.front();
            q.pop();

            int node = it.first;
            int parentnode = it.second;
            for(auto nextnode :adj[node])
            {
                if(!vis[nextnode])
                {
                    vis[nextnode]=true;
                    q.push({nextnode,node});
                }
                else if(nextnode!=parentnode)
                    return true;

            }
        }

        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis(V,0);
        bool ans =false;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
                if(solveBFS(i,V,adj,vis))  return true;
        }
        // bool ans = solveBFS(0,V,adj,vis);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends