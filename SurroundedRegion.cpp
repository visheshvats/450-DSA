#include<bits/stdc++.h>

using namespace std;

void dfs(int x, int y, vector<vector<int>> &board, vector<vector<int>> &vis, vector<int> &delrow, vector<int> &delcol,
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

class Solution {
public:
    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();
        
        vector<int> delrow = {1,0,-1,0};
		vector<int> delcol = {0,1,0,-1};

        vector<vector<int>> vis(n, vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            
        }

        
    }
};