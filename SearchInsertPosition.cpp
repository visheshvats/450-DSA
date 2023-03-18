#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size()==0)  return 0;
        if(target<=nums[0]) return 0;
        int n= nums.size();
        if(nums[n-1]==target)   return n-1;
        if(nums[n-1]<target)   return n;

        int l=0;
        int r=n-1;
        int mid;
        while(l<=r)
        {
            mid=l+((r-l)/2);
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]>target)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return l;

        
    }
};