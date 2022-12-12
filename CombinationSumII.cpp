#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rec(int ind, int n, int target, vector<int> &candidates, vector<int>& temp,vector<vector<int>> &res)
    {
        //bc
        if(target==0)
        {
            res.push_back(temp);
        }
        




        //rc
        for(int i=ind; i<candidates.size();i++)
        {
            if(i>ind&&candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            temp.push_back(candidates[i]);
            rec(i+1,n,target-candidates[i],candidates,temp,res);
            temp.pop_back();

        }
        





    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<vector<int> > res;
        vector<int> temp;
        // int tempp=0;
        sort(candidates.begin(),candidates.end());
        



        rec(0, candidates.size(), target, candidates, temp, res);

       
        return res;

        
    }
};