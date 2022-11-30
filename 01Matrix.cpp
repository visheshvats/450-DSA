#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n=mat.size();
        int m = mat[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));
        vector<vector<int>> ans(n, vector<int>(m,0));

        queue <pair<pair<int, int>, int>> q;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({{i,j},0});
                    vis[i][j]=1;

                }
            }
        }

        vector<int> delrow = {1,0,-1,0};
		vector<int> delcol = {0,1,0,-1};

        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            q.pop();

            for(int i=0;i<4;i++)
            {
                int nrow = r+delrow[i];
                int ncol = c+delcol[i];

                if(nrow>=0&&ncol>=0&&nrow<n&&ncol<m&&vis[nrow][ncol]==0)
                {
                    q.push({{nrow, ncol}, d+1});
                    vis[nrow][ncol]=1;
                    ans[nrow][ncol]=d+1;
                }
            }



        }



        return ans;




        
    }
};