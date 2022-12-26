#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            int target = -nums[i];
            int l=i+1;
            int r = nums.size()-1;
            while (l<r)
            {
                int sum = nums[l]+nums[r];
                if(target==sum)
                {
                    vector<int> temp{nums[i],nums[l],nums[r]};
                    res.push_back(temp);
                    while(l<r&&nums[l]==temp[1]) l++;
                    while(l<r&&nums[r]==temp[2]) r--;
                }
                else if(target<sum)
                {
                    r--;
                }
                else if(target>sum)
                {
                    l++;
                }

            }

            while(i<n-1&&nums[i+1]==nums[i])
            {
                i++;
            }
            
        }


        return res;
    }
};
