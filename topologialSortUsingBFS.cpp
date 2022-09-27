#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> topo(int N, vector<int> adj[]) {
        vector<int> topo;
        queue<int> q;
        vector<int> indegree(N,0);

        for(int i=0;i<N;i++)
        {
            for(auto it:adj[i])
                indegree[it]++;
        }

        for(int i=0;i<N;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }

        while(!q.empty())
        {
            int n= q.front();
            q.pop();
            for(auto it: adj[n])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
                
            }
            topo.push_back(n);
        }


        return topo;
	}
};



int main()
{

    	vector<int> adj[6];
    	adj[5].push_back(2);
    	adj[5].push_back(0);
    	adj[4].push_back(0);
    	adj[4].push_back(1);
    	adj[3].push_back(1);
    	adj[2].push_back(3);

    	Solution obj;
    	vector<int> v=obj.topo(6, adj);
    	for(auto it:v)
    	cout<<it<<" ";
    

    return 0;
}