#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rec(int i, int n, int target, vector<int> &candidates, vector<int> &temp, vector<vector<int>> &res, int tempp)
    {
        //bc
        if(i==n||tempp>target)
        {
            

            return;

        }
        if(tempp==target)
        {
            res.push_back(temp);
            return;
        }




        //rc
        temp.push_back(candidates[i]);
        tempp+=candidates[i];
        rec(i,n, target, candidates, temp, res, tempp);
        tempp-=candidates[i];
        temp.pop_back();
        rec(i+1,n, target,candidates,temp, res, tempp);


        return;





    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int> > res;
        vector<int> temp;
        int tempp=0;



        rec(0, candidates.size(), target, candidates, temp, res, tempp);


        return res;

        
    }
};