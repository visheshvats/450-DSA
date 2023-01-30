#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> res(rocks.size(),0);
        for(int i=0;i<rocks.size();i++)
        {
            res[i]=(capacity[i]-rocks[i]);
        }
        int temp = additionalRocks;

        sort(res.begin(),res.end());
        for(int i=1;i<rocks.size();i++)
        {
            res[i]+=res[i-1];
        }
        int count =0;
        for(int i=0;i<rocks.size();i++)
        {
            if(res[i]>temp)
                break;
            
            count++;

        }

        return count;
    }
};