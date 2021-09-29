#include <bits/stdc++.h>
using namespace std;

int maxxx(vector<int> prices, int money)
{
    
    

    int maxSum = 0;
    int curSum = 0;
    int start = 0;
    int end = 0;
    while(start < prices.size()){

        if(curSum > maxSum && curSum <= money){
            maxSum = curSum;
        }
        if(curSum <= money && end < prices.size()){
            curSum += prices[end];
            end += 1;

        }
        else{
            curSum -= prices[start];
            start+= 1;
        }
    }
    return maxSum;

}