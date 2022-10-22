#include <bits/stdc++.h>
using namespace std;
int maxLen = 0;
int cnt;

class Graph {
	int V;

	list<int>* adj;
	multimap<int, int> adj2;
	void DFSUtil(int v, bool visited[]);

public:
	Graph(int V);

	void addEdges();
	void removeEdges(int V, int Edges[][2],
					int E, int queries[],
					int Q);
	int NumberOfconnectedComponents();
};

// function to find the number of connected
// component in undirected graph
int Graph::NumberOfconnectedComponents()
{

	bool* visited = new bool[V];

	int count = 0;
	for (int v = 0; v < V; v++)
		visited[v] = false;

	for (int v = 0; v < V; v++) {
		if (visited[v] == false) {
			cnt = 0;
			DFSUtil(v, visited);
			count += 1;
		}
	}

	return count;
}

void Graph::DFSUtil(int v, bool visited[])
{
	visited[v] = true;
	cnt++;

	list<int>::iterator i;

	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i]) {
			DFSUtil(*i, visited);
		}
	maxLen = max(maxLen, cnt);
}

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

// add Edges in the graph
void Graph::addEdges()
{
	for (auto x : adj2) {
		adj[x.first].push_back(x.second);
		adj[x.second].push_back(x.first);
	}
}

// function to remove all the edges that are
// connected with vertices
void Graph::removeEdges(int V, int Edges[][2],
						int E, int queries[],
						int Q)
{
	multimap<int, int> adj3;
	for (int i = 0; i < E; i++)
		adj3.insert({ Edges[i][0], Edges[i][1] });

	for (int i = 0; i < Q; i++) {
		auto it1 = adj3.lower_bound(queries[i]);
		auto it2 = adj3.upper_bound(queries[i]);
		adj3.erase(it1, it2);
	}

	for (auto it = adj3.begin(); it != adj3.end(); it++) {
		adj2.insert({ it->second, it->first });
	}
	for (int i = 0; i < Q; i++) {
		auto it1 = adj2.lower_bound(queries[i]);
		auto it2 = adj2.upper_bound(queries[i]);
		adj2.erase(it1, it2);
	}
}

// Driver code
int main()
{
	int V = 6, E = 7;
	Graph g(V);
	int Edges[][2] = { { 0, 1 }, { 0, 3 }, { 0, 4 }, { 1, 3 }, { 1, 2 }, { 2, 4 },{2,5} };
	int Q = 1;
	int queries[] = { 2 };
	// remove all the edges that are connected with
	// vertices given in the queries
	g.removeEdges(V, Edges, E, queries, Q);

	g.addEdges();

	cout << g.NumberOfconnectedComponents() - Q;
	cout << " " << maxLen;

	return 0;
}
