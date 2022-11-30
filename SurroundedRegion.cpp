#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    void dfs(int x, int y, vector<vector<char>> &board, vector<vector<int>> &vis, vector<int> &delrow, vector<int> &delcol,
                int m, int n)
                {
                    vis[x][y]=1;

                    for(int i=0;i<4;i++)
                    {
                        int nrow = x+delrow[i];
                        int ncol = y+delcol[i];

                        if(nrow>=0&&ncol>=0&&nrow<n&&ncol<m&&vis[nrow][ncol]==0&&board[nrow][ncol]=='O')
                        {
                            dfs(nrow, ncol, board, vis, delrow, delcol, m, n);
                        }
                    }

                }
                
    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();
        
        vector<int> delrow = {1,0,-1,0};
		vector<int> delcol = {0,1,0,-1};

        vector<vector<int>> vis(n, vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            if(vis[i][0]==0&&board[i][0]=='O')
            {

                dfs(i,0, board, vis, delrow,delcol, m, n);
            }

            if(vis[i][m-1]==0&&board[i][m-1]=='O')
            {
                dfs(i,m-1,board,vis,delrow, delcol, m, n);
            }    
        }

        for(int i=0;i<m;i++)
        {
            if(vis[0][i]==0&&board[0][i]=='O')
            {

                dfs(0,i, board, vis, delrow,delcol, m, n);
            }

            if(vis[n-1][i]==0&&board[n-1][i]=='O')
            {
                dfs(n-1,i,board,vis,delrow, delcol, m, n);
            }

        }

        
    }
};