#include <bits/stdc++.h>
using namespace std;




class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         vector<vector<int>> result;
        if(intervals.size()==0)
            return result;
        
        sort(intervals.begin(),intervals.end());
        vector<int> temp=intervals[0];
        for(int i=0;i<intervals.size();i++)
        {
            if(temp[1]>=intervals[i][0])
                temp[1]=max(temp[1],intervals[i][1]);
            else
            {
                result.push_back(temp);
                temp=intervals[i];
            }

        }

        result.push_back(temp);
        return result;
        
    }
};