#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxcount =0;
        int tempcount=0;

        for(auto it: nums)
        {
            if(it==1)
            {
                tempcount++;
                maxcount=max(maxcount,tempcount);
            }
            else
            {
                tempcount=0;
            }
        }
        return maxcount;
        
    }
};