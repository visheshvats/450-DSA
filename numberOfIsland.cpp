#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isValid(int i, int j, int m, int n)
    {
        if(i<0||j<0)    return false;
        if(i>=m||j>=n)  return false;

        return true;
    }

    void dfs(int x, int y, int m, int n, vector<vector<bool>> & vis,
             vector<vector<char>> &grid,
            vector<int>&delrow, vector<int>&delcol)
    {
        vis[x][y]=true;
        for(int i=0;i<4;i++)
        {
            int a = x + delrow[i];
            int b = y +delcol[i];
            if(isValid(a,b,m,n))
            {
                if(!vis[a][b]&&grid[a][b]=='1')
                {
                    dfs(a,b,m,n,vis,grid,delrow,delcol);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool> (n,0));

        int count =0;
        vector<int>delrow = {0,1,0,-1};
        vector<int>delcol = {1,0,-1,0};


        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j]&&grid[i][j]=='1')
                {
                    count++;
                    dfs(i,j,m, n,vis,grid,delrow,delcol);
                }
            }
        }

        return count;
        
    }
};