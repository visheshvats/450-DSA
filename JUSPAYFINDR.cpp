#include<bits/stdc++.h>
using namespace std;

void dfs(int src,int dest,unordered_map<int,int>&vis){
	vis[src]=1;
	for(int i=0;i<adj[src].size();++i){
		if(!vis[adj[src][i]]){
			dfs(adj[src][i],dest,vis);
		}
	}
}
unordered_map<int, int> takeelement(int n)
{
    unordered_map<int,int>vis;
    for(int i=0;i<n;++i){
		int x;
		cin>>x;
		vis[x]=0;
	}
    return vis;
}

vector<int> makemap(int e)
{
    vector<int>adj[];
    for(int i=0;i<e;++i)
    {
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
	}
}


int main(){
    vector<int>adj[];
	unordered_map<int,int>vis;
	int n;
	cin>>n;
    vis = takeelement(n);
	int e;
	cin>>e;
    adj = makemap(e);
	int src,dest;
	cin>>src>>dest;
	dfs(src,dest,vis);
	cout<<vis[dest]<<endl;
	return 0;	
}