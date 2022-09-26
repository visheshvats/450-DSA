#include<bits/stdc++.h>

using namespace std;

class Solution {

  
    
  public:

    bool dfscycle(int i, int V, vector<int> adj[], vector<bool> &vis)
    {
        vis[i]=true;
        

        return false;
    }


    bool isCycle(int V, vector < int > adj[]) {
        
        vector<bool> vis(V+1,0);
        for(int i=1;i<=V;i++)
        {
            if(!vis[i])
            {
                if(dfscycle(i,V,adj,vis))
                    return true;
            }
                
        }
        
        return false;
      
    }
};

// { Driver Code Starts.
int main() {

  int V = 5;
  int E = 5;
  vector < int > adj[V];

  adj[0].push_back(1);
  adj[1].push_back(0);

  adj[1].push_back(2);
  adj[2].push_back(1);

  adj[1].push_back(4);
  adj[4].push_back(1);

  adj[4].push_back(3);
  adj[3].push_back(4);

  adj[2].push_back(3);
  adj[3].push_back(2);

  Solution obj;
  bool ans = obj.isCycle(V, adj);
  if (ans) {
    cout << "Cycle Detected";
  } else cout << "No Cycle Detected";

  return 0;
}