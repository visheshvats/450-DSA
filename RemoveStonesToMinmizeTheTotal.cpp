#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> heap(piles.begin(),piles.end());
        int sum =0;
        for(auto it: piles)
            sum+=it;
        int temp =k;
        while (k--)
        {
            int top = heap.top();
            heap.pop();
            int num = top/2;
            sum-=num;
            heap.push(top-num);
        }

        return sum;
        
        
    }
};