#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> a;
        int maxi=0;
        int temp =0;
        int left =0;

        

        for(int i=0;i<s.size();i++)
        {
            if(a.find(s[i])==a.end())
            {
                a.insert(s[i]);
                temp++;
                maxi=max(maxi,left-i+1);
            }
            else
            {
                while(a.find(s[i])!=a.end())
                {
                    a.erase(s[left]);
                    left++;
                }
                a.insert(s[i]);

            }

        }

        return maxi;
        
    }
};