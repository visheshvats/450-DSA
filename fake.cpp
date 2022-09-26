#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool checkCycle(int i,vector<int>&vis,vector<int>&temp,vector<int>graph[]){
        vis[i]=1;
        temp[i]=1;
        for(auto j :graph[i]){
            if(!vis[j]){
                if(checkCycle(j,vis,temp,graph))
                    return true;
            }
            else if(temp[j])
                return true;
        }
        temp[i]=0;
        return false;
    }
    
    
    bool canFinish(int num, vector<vector<int>>& pre) {
        vector<int>graph[num];
        for(auto i:pre)
            graph[i[1]].push_back(i[0]);
        vector<int>vis(num,0);
        vector<int>temp(num,0);
        for(int i=0;i<num;i++){
            if(!vis[i]){
                if(checkCycle(i,vis,temp,graph))
                    return false;
            }
        }
        return true;
        
        
    }
};