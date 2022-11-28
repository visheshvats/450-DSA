#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int x,int y, int n, int m, vector<vector<char>>& grid, vector<vector<int>>& vis){
        if (x<0 || y<0 || x>=n || y>=m || vis[x][y] || grid[x][y]=='0')return;
        vis[x][y]=1;
        dfs(x-1,y,n,m,grid,vis);
        dfs(x+1,y,n,m,grid,vis);
        dfs(x,y+1,n,m,grid,vis);
        dfs(x,y-1,n,m,grid,vis);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n= grid.size(); int m= grid[0].size();
        int cnt=0;
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                
                vis[i].push_back(0);
            }
        }
        
        for (int it=0; it<n; it++){
            for (int at=0; at<m; at++){
                
                if (!vis[it][at] && grid[it][at]=='1'){
                    
                    dfs(it,at,n,m,grid,vis);
                    cnt++;
                }
                
            }
        }
        return cnt;
    }
};