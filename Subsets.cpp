#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rec(int i, int n, vector<int> &temp, vector<vector<int>> &res, vector<int> &nums)
    {
        if(i==n)
        {
            res.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        rec(i+1, n, temp, res, nums);
        temp.pop_back();
        rec(i+1, n, temp, res, nums);

        return;

        
    }
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> res;
        vector<int> temp;
        int n = nums.size();


        rec(0,n, temp, res, nums);

        return res;

        
    }
};