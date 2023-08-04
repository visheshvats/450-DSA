#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> ans(0, n);
        int maxi=INT_MIN;

        for(int i=0;i<n;i++)
        {
            maxi=max(maxi, candies[i]);
        }

        maxi=maxi-extraCandies;

        for(int i=0;i<n;i++)
        {
            ans[i]=candies[i]>maxi;
        }

        return ans;
    }
};