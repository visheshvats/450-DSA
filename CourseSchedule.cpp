#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(int i, queue<int> &q, vector<bool> &vis, vector<int> &ans, vector<int> &indegree, int numCourses)
    {
        


    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> adj[numCourses];
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> indegree(numCourses,0);

        for(int i=0;i<numCourses;i++)
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;
        vector<bool> vis(numCourses,0);
        vector<int> ans;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
                vis[i]=true;
            }
        }

        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
                bfs(i,q,vis,ans,indegree, numCourses);
        }
        
    }
};