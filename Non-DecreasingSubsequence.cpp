#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ans;
        int n = nums.size();
        for(int bit=1;bit<(1<<n);bit++)
        {
            vector<int> temp;
            for(int i=0;i<n;i++)
            {
                if(((1<<i)&bit)!=0)
                {
                    temp.push_back(nums[i]);
                }
            }
            if(temp.size()>=2)
            {
                bool t=1;
                for(int i=0;i<temp.size()-1;i++)
                {
                    if(temp[i]>temp[i+1])
                    {
                        t=0;
                    }
                }
                if(t)
                {
                    ans.insert(temp);
                }

            }

        }

        return vector(ans.begin(),ans.end());
    }
};