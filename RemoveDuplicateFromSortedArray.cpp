#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=1;
        for(;j<nums.size();j++)
        {
            if(nums[i]==nums[j])
            {
                continue;
            }
            else
            {
                i++;
                nums[i]=nums[j];
            }
        }

        return i+1;
    }
};