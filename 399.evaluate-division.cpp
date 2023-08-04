#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations,
     vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        unordered_map<string, vector<pair<string, double>>> g;
        for(int i=0;i<equations.size();i++)
        {
            g[equations[i][0]].push_back({equations[i][1],values[i]});
            g[equations[i][1]].push_back({equations[i][0],1/values[i]});
        }
        for(int i=0;i<queries.size();i++)
        {
            string start = queries[i][0];
            string end = queries[i][1];
        }
    }
};
