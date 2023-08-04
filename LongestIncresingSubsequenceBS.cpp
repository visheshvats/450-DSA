#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<int> temp;
        for(int i=0;i<n;i++)
        {
            if(temp.empty()||nums[i]>temp.back())
            {
                temp.push_back(nums[i]);
            }
            else
            {
                auto it = lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[it]=nums[i];
            }
        }

        return temp.size();
        
    }
};