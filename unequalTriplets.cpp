#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int unequalTriplets(vector<int>& nums)
    {
        unordered_map<int,int> mp;
        for(auto it:nums)
        {
            mp[it]++;

        }

        int i=0;int j=nums.size();
        int count=0;
        for(auto [n, cnt]:mp)
        {
            j-=cnt;
            count+=i*cnt*j;
            i+=cnt;
        }

        return count;
    }
};