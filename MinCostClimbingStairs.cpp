#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &cost, int n)
{

    vector<int> dp(n+1, -1 );
    int prev=cost[0];
    int next=cost[1];

    for(int i=2;i<n;i++)
    {
        int curr=min(prev,next)+cost[i];
        prev = next;
        next = curr;
    }

    return min(prev, next);
}

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        int ans = solve(cost, n);
        return ans;
        
    }
};