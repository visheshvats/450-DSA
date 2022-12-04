#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<int> a;
        for(int i=0;i<n/2;i++)
        {
            int t = nums[i]+nums[n-i-1];
            a.insert(t);
        }

        return a.size();
        
    }
};