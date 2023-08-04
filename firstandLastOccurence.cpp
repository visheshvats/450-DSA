#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans={-1,-1};
        if(nums.size()==0)  return ans;
        int x = lower_bound(nums.begin(), nums.end(), target)-nums.begin(); 
        
        if(x==nums.size())  return ans;
        if(nums[x]!=target) return ans;
        
        int y = upper_bound(nums.begin(), nums.end(), target)-nums.begin(); 
        ans[0]=x;
        ans[1]=y-1;

        return ans;

    }
};