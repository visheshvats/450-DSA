#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool cycledfs(int i, vector<int> adj[], vector<bool> &visited, vector<bool> &dfsvisited)
    {
        visited[i]=true;
        dfsvisited[i]=true;
        
        for(auto it:adj[i])
        {
            if(visited[it]==false)
            {if(cycledfs(it, adj,visited, dfsvisited)) return true;}
            else if(dfsvisited[it]==true) return true;

        }

        dfsvisited[i]=false;

        return false;

        
        
    }
    
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        
        vector<int> adj[numCourses];
        
        for(auto i:prerequisites)
        {
            adj[i[0]].push_back(i[1]);
            
        }
        
        vector<bool> visited(numCourses,false);
        vector<bool> dfsvisited(numCourses,false);
        
        for(int i=0;i<numCourses;i++)
        {
            if(visited[i]==false){
                if(cycledfs(i,adj,visited, dfsvisited)) return false;}
        }
        
        
        return true;
        
        
    }
};