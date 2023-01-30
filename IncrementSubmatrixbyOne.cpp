#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>ans (n, vector<int>(n,0));
        int m = queries.size();
        for(auto it: queries)
        {
            int r1=it[0];
            int c1=it[1];
            int r2=it[2];
            int c2=it[3];

            ans[r1][c1]++;
            if(r2+1<n&&c2+1<n)  ans[r2+1][c2+1]+=1;
            if(r2+1<n)  ans[r2+1][c1]-=1;
            if(c2+1<n)  ans[r1][c2+1]-=1;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<n;j++)
            {
                ans[i][j]=ans[i][j]+ans[i][j-1];
            }
        }

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans[i][j]=ans[i][j]+ans[i-1][j];
            }
        }

        return ans;
        
    }
};