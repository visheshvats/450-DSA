#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int lbs(vector<int> & nums, int target)
    {
        int low=0;
        int high=nums.size();
        int ans=-1;
        while(high>=low)
        {
            int mid = low+(high-low)/2;
            if(nums[mid]==target)
            {
                ans =mid;
                high=mid-1;
            }
            else if(nums[mid]>target)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }

        return ans;
    }

    int hbs(vector<int> &nums, int target)
    {
        int low=0;
        int high=nums.size();
        int ans=-1;
        while(high>=low)
        {
            int mid = low+(high-low)/2;
            if(nums[mid]==target)
            {
                ans =mid;
                high=mid+1;
            }
            else if(nums[mid]>target)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }

        return ans;

    }
    vector<int> searchRange(vector<int>& nums, int target) {

        int a = lbs(nums, target);
        int b= hbs(nums, target);

        vector<int> ans;
        ans.push_back(a);
        ans.push_back(b);

        return ans;
        
    }
};