#include <bits/stdc++.h>

using namespace std;

class Solution {
    
  public:
    
    void DFStopoSort(int i, int N, vector<int> adj[], vector<bool> &vis, stack<int> &st)
    {
        vis[i]=true;
        for(auto it: adj[i])
        {
            if(!vis[it])
                DFStopoSort(it, N, adj, vis, st);
        }

        st.push(i);
    }

    vector < int > topoSort(int N, vector < int > adj[]) 
    {
        stack<int> st;
        vector<bool> vis(N,0);

        for(int i=0;i<N;i++)
        {
            if(!vis[i])
            {
                DFStopoSort(i, N, adj, vis, st);
            }
        }

        vector<int> res;
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();

        }

        return res;
      

    }
};

// { Driver Code Starts.
int main() {

  int N = 6;

  vector < int > adj[5 + 1];

  adj[5].push_back(2);
  adj[5].push_back(0);
  adj[4].push_back(0);
  adj[4].push_back(1);
  adj[2].push_back(3);
  adj[3].push_back(1);

  Solution obj;
  vector < int > res = obj.topoSort(6, adj);

  cout << "Toposort of the given graph is:" << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }

  return 0;
}