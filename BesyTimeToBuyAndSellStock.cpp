#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0)    return 0;
        int minsofar=prices[0];
        int maxProfitSoFar=0;
        for(int i=0;i<prices.size();i++)
        {
            minsofar=min(minsofar,prices[i]);
            int currprofit=prices[i]-minsofar;
            maxProfitSoFar=max(maxProfitSoFar, currprofit);

        }

        return maxProfitSoFar;
        
    }
};