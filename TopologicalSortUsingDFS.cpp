#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
    void findTopoSortDFS(int i, vector<int>adj[], stack<int> &st, vector<bool> &vis)
    {

        vis[i]=true;

        for( auto it: adj[i])
        {
            if(!vis[it])
                findTopoSortDFS(it, adj, st, vis);
        }

        st.push(i);



    }
  
  
  public:
    vector < int > topoSort(int N, vector < int > adj[]) {
      stack <int> st;
      vector<bool> vis(N,0);
      vector<int> res;

      for(int i=0;i<N;i++)
      {
        if(!vis[i])
            findTopoSortDFS(i,adj,st,vis);
      }

      while (!st.empty())
      {
        /* code */
        int t = st.top();
        res.push_back(t);
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