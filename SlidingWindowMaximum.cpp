#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;

        multiset<int> temp;

        for(int i=0;i<k;i++)
        {
            temp.insert(nums[i]);
        }
        

        for(int i=k-1;i<nums.size()-1;i++)
        {
            ans.push_back(*temp.rbegin());
            auto it = temp.find(nums[i-k+1]);
            temp.erase(it);
            temp.insert(nums[i+1]);
            

        }
        ans.push_back(*temp.rbegin());

        return ans;
        
    }
};