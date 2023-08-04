#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solveSO(vector<int> &nums)
    {
        // vector<int> dp(n+1,0);
        int n=nums.size();
        if(n==0)    return 0;
        if(n==1)    return nums[0];
        if(n==2)    return max(nums[0],nums[1]);
        int a=nums[0];
        int b=max(nums[0],nums[1]);
        int c;

        for(int i=3;i<=n;i++)
        {
            c =max(nums[i-1]+a,b);
            a=b;
            b=c;
        }
        return b;
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)    return 0;
        if(n==1)    return nums[0];
        if(n==2)    return max(nums[0],nums[1]);
        vector<int> a(nums.begin(),nums.end()-1);
        vector<int> b(nums.begin()+1,nums.end());

        return max(solveSO(a),solveSO(b));

        
    }
};