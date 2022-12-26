#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum =0;
        int count = 0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            mp[sum]++;
            if(mp.find(sum-k)!=mp.end())
                count += mp[sum-k];
        }

        return count;
    }
};