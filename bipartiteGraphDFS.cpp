#include <bits/stdc++.h>
using namespace std;

bool bipartiteDFS(int i, vector<int> adj[], int n, vector<int> &color)
{
    for(auto it: adj[i])
    {
        if(color[it]==-1)
        {
            color[it]=1-color[i];
            if(!bipartiteDFS(it,adj,n,color))
                return false;
            
        }
        else if(color[it]==color[i])
            return false;
    }

    return true;
    
}


bool checkBipartite(vector<int> adj[], int n) {

    vector<int> color(n,-1);

    for(int i=0;i<n;i++)
    {
        if(color[i]==-1)
        {
            color[i]=0;
            if(!bipartiteDFS(i,adj,n,color))
                return false;
        }

    }

    return true;

    
}
void addedge(vector<int> adj[],int u,int v)
{
        adj[u].push_back(v); 
        adj[v].push_back(u);
}
int main() {
    
    vector<int> adj[6];
    addedge(adj,0,1);
    addedge(adj,1,2);
    addedge(adj,1,4);
    addedge(adj,1,5);
    addedge(adj,2,3);
    addedge(adj,3,4);
    addedge(adj,3,5);

    if(checkBipartite(adj, 6)) {
        cout << "It is a Bipartite Graph"; 
    } else {
        cout << "It is not a Bipartite Graph"; 
    }
    return 0;
}