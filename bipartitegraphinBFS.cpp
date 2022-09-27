#include <bits/stdc++.h>
using namespace std;

bool biparititeBfs(int i, int n, vector<int> adj[], vector<int> &color)
{
	queue<int> q;
	q.push(i);
	color[i]=0;
	while(!q.empty())
	{
		int n = q.front();
		q.pop();
		for(auto it: adj[n])
		{
			if(color[it]==-1)
			{
				q.push(it);
				color[it]=1-color[n];
			}
			else if(color[it]==color[n])
				return false;
				
		}

	}

	return true;
}


bool checkBipartite(vector<int> adj[], int n) {
    
    vector<int> color(n,-1);

    for(int i=0;i<n;i++)
    {
        if(color[i]==-1)
            if(!biparititeBfs(i,n,adj, color))
                return false;

    }


    return true;

    
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> adj[n];
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v;
	    adj[u].push_back(v); 
	    adj[v].push_back(u); 
	}
	
	if(checkBipartite(adj, n)) {
	    cout << "yes"; 
	} else {
	    cout << "No"; 
	}
	return 0;
}

/*
8 7 
0 1 
1 2 
2 3 
3 4 
4 6 
6 7 
1 7
4 5 

// bipartite graph example 
*/ 

/*
7 7 
0 1 
1 2 
2 3 
3 4 
4 6 
6 1
4 5 
// not bipartite example
*/