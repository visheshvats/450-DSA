#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &m, int n)
    {
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
        for(int i=0;i<n;i++)
        {
            int temp  = solve(0,i,matrix,n);
            ans=min(temp,ans);

        }

        return ans;
        
    }
};
