#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool bfs(int x, int y, int m, int n, vector<vector<bool>> &vis, vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        q.push({x,y});
        vis[x][y]=1;
        bool isClosed=1;

        vector<int> delrow{0, 1, 0, -1};
        vector<int> delcol{-1, 0, 1, 0};

        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;

            q.pop();
            for(int i=0;i<4;i++)
            {
                int r = x+delrow[i];
                int c = y+delcol[i];
                if(r<0||c<0||r>=m||c>=n)
                {
                    isClosed=0;
                    
                }
                else if(grid[r][c]==0&&vis[r][c]==0)
                {
                    q.push({r,c});
                    vis[r][c]=true;
                }
            }



        }

        return isClosed;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n,0));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0&&vis[i][j]==0&&bfs(i,j, m,n, vis, grid))
                    count++;
            }
        }
        

        return count++;
    }
};