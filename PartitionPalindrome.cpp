#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s, int start, int end)
    {
        while(start<=end)
        {
            if(s[start++]!=s[end--])
                return false;
        }

        return true;
    }
    void solve(int start, string s, vector<string> &current, vector<vector<string>> &res)
    {
        if(start>=s.size()) res.push_back(current);
        for(int end=start;end<s.size();end++)
        {
            if(isPalindrome(s,start,end))
            {
                current.push_back(s.substr(start,end-start+1));
                solve(end+1,s,current,res);
                current.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> current;
        solve(0,s,current, res);

        return res;
        
    }
};