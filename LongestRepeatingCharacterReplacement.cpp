#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {

        vector<int> cha(26,0); 

        int l=0;
        int r=0;
        int maxi=0;

        for(r=0;r<s.size();r++)
        {
            if(l-r+1 - *max_element(cha.begin(),cha.end())<=k)
            {
                maxi=max(maxi,l-r+1);
                cha[s[r]-'A']++;
            }
            else
            {
                while(l-r+1-*max_element(cha.begin(),cha.end())<=k)
                {
                    cha[s[l]-'A']--;
                    l++;
                }
                maxi=max(maxi,l-r+1);
                cha[s[r]-'A']++;
            }

            
        }

        return maxi;
        
    }
};