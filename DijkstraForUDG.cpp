#include<bits/stdc++.h>
using namespace std;
int main(){
	int n=5,m=6,source=1;
	vector<pair<int,int> > g[n+1]; 	// assuming 1 based indexing of graph
	// Constructing the graph
	g[1].push_back({2,2});
	g[1].push_back({4,1});
	g[2].push_back({1,2});
	g[2].push_back({5,5});
	g[2].push_back({3,4});
	g[3].push_back({2,4});
	g[3].push_back({4,3});
	g[3].push_back({5,1});
	g[4].push_back({1,1});
	g[4].push_back({3,3});
	g[5].push_back({2,5});
	g[5].push_back({3,1});	
	// Dijkstra's algorithm begins from here
	
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int>distTo(n+1,INT_MAX);

    distTo[source] = 0;
    pq.push(make_pair(0, source));


    while(!pq.empty())
    {
        int n = pq.top().first;
        int t = pq.top().second;
        pq.pop();
        for(auto it : g[t])
        {
            int w = it.second; //weight of Next Node
            int nn=it.first;    //node number of next node
            if(distTo[it.first]>distTo[t]+it.second)
            {
                distTo[it.first]=distTo[t]+it.second;   //updating node weight
                pq.push(make_pair(distTo[it.first],it.first));  //pushing back newly updated node
            }
            
        }
    }
	
    cout << "The distances from source " << source << " are : \n";
	for(int i = 1 ; i<=n ; i++)	cout << distTo[i] << " ";
	cout << "\n";
	return 0;
}