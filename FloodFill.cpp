#include<bits/stdc++.h>
using namespace std;

//DFS Solution

class Solution {
public:
    bool issafe(int x, int y, int color, int inicolor, vector<vector<int>> &ans, 
                vector<vector<int>> &image, int m , int n)
    {
        if(x>=0&&y>=0&&x<m&&y<n&&image[x][y]==inicolor&&ans[x][y]!=color)
            return 1;
        return 0;
        
    }
    void dfs(int x, int y,int color, int inicolor, vector<vector<int>> &ans, 
                vector<vector<int>> & image, vector<int> &delrow, vector<int> & delcol, int m, int n)
    {
        ans[x][y]=color;
        for(int i=0;i<4;i++)
        {
            int a = x+delrow[i];
            int b = y+delcol[i];
            if(issafe(a,b,color, inicolor, ans, image, m, n))
                dfs(a,b,color,inicolor,ans, image, delrow, delcol, m, n);
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int inicolor= image[sr][sc];

        vector<vector<int>> ans = image;
        vector<int> delrow{1,0,-1,0};
        vector<int> delcol{0,1,0,-1};

        if(image[sr][sc]==color)    return ans;
        
        dfs(sr,sc, color,inicolor, ans, image,delrow, delcol, m, n);
        return ans;
        
    }
};