#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n];
        int item = times.size();
        //preparing adj list

        for(int i=0;i<item;i++)
        {
            adj[times[i][0]].push_back({times[i][1],times[i][2]});

        }

        //now doing Dijkstra

        


        
    }
};