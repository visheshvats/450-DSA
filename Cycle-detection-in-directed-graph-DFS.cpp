#include<bits/stdc++.h>

using namespace std;

class Solution {
  private:
    
  public:

    bool DFSisCyclic(int i, int N, vector<int> adj[],vector<bool> &vis, vector<bool> &dfsvis)
    {
        vis[i]=true;
        dfsvis[i]=true;
        for(auto it: adj[i])
        {
            if(!vis[it])
            {
                if(DFSisCyclic(it, N, adj, vis, dfsvis))
                    return true;

            }
            else if(dfsvis[i])
                return true;
        }


        
        dfsvis[i]=false;
        
        
        
        return false;
    }

    bool isCyclic(int N, vector < int > adj[]) 
    {
        vector<bool> vis(N,0);
        vector<bool> dfsvis(N,0);

        for(int i=0;i<N;i++)
        {
            if(!vis[i])
            {
                if(DFSisCyclic(i,N,adj,vis,dfsvis))
                    return true;
            }
        }


        return false;

    }
};

void addEdge(vector < int > adj[], int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

int main() {

  int V = 6;

  vector < int > adj[V];
  addEdge(adj, 0, 1);
  addEdge(adj, 1, 2);
  addEdge(adj, 1, 5);
  addEdge(adj, 2, 3);
  addEdge(adj, 3, 4);
  addEdge(adj, 4, 0);
  addEdge(adj, 4, 1);

  Solution obj;
  if (obj.isCyclic(V, adj))
    cout << "Cycle Detected" << "\n";
  else
    cout << "No Cycle Detected";

  return 0;
}