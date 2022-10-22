#include<bits/stdc++.h>
using namespace std;

int main(){
	int N=5,m=6;
	vector<pair<int,int> > adj[N]; 


	adj[0].push_back({1,2});
	adj[0].push_back({3,6});
	adj[1].push_back({0,2});
	adj[1].push_back({2,3});
	adj[1].push_back({3,8});
	adj[1].push_back({4,5});
	adj[2].push_back({1,3});
	adj[2].push_back({4,7});
	adj[3].push_back({0,6});
	adj[3].push_back({1,8});
	adj[4].push_back({1,5});
	adj[4].push_back({2,7});
	
    vector<int> parent(N,-1);
    vector<bool> mst(N,0);
    vector<int> key(N, INT_MAX);
    key[0]=0;

    for(int i=0;i<N-1;i++)
    {
        int mini =INT_MAX;
        int u=0;
        for(int v=0;v<N;v++)
        {
            if(mst[v]==false&&(key[v]<mini))
            {
                mini = key[v];
                u=v;
            }
        }

            mst[u]=true;
            for(auto it : adj[u])
            {
                int v=it.first;
                int weight = it.second;

                if(mst[v]==false&&(weight<key[v]))
                {
                    key[v]=weight;
                    parent[v]=u;
                }
            }
        
    }
    
    
    for (int i = 1; i < N; i++) 
        cout << parent[i] << " - " << i <<" \n"; 
	return 0;
}