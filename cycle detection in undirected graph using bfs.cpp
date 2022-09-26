#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool checkForCycle(int i, int V, vector<int> adj[], vector<bool> vis)
    {
        queue<pair<int, int>> q;
        vis[i]=true;
        q.push({i,-1});
        while(!q.empty())
        {
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
            for( auto it : adj[node])
            {
                if(!vis[it])
                {
                    vis[it]=true;
                    q.push({it, node});
                }
                if(it!=par)
                    return true;
            }

        }

        
        
        
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[])
    {
        vector<bool> vis(V+1,0);
        for(int i=1;i<=V;i++)
        {
            if(!vis[i])
                if(checkForCycle(i,V,adj,vis))
                    return true;
        }
        return false;
    }
};
 
void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main()
{
    vector<int> adj[5];
   
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,2,3);
    addEdge(adj,1,3);
    addEdge(adj,2,4);
   
    Solution obj;
    int num=obj.isCycle(5, adj);
    if(num==1)
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;
 
    return 0;
}