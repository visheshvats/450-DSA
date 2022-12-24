#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int i)
    {
        int x = 1;
        while (i+1 > 1 << x)
            x++;

        return x;
    }
    vector<int> cycleLengthQueries(int n, vector<vector<int>> &queries)
    {
        vector<int> ans;
        for (int i = 0; i < queries.size(); i++)
        {
            int a = queries[i][0];
            int b = queries[i][1];
            int x = solve(a);
            int y = solve(b);
            int tt=0;
            // if(a%2==0)
            //     tt++;
            // if(b%2==0)
            //     tt++;
            int t = x + y - 1+tt;
            ans.push_back(t);
        }

        return ans;
    }
};