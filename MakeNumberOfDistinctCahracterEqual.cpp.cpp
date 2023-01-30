#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool isItPossible(string word1, string word2) {
        vector<int> mp1(26,0), mp2(26,0);
        for(int i=0;i<word1.size();i++)
        {
            mp1[word1[i]-'a']++;
        }
        for(int i=0;i<word2.size();i++)
        {
            mp2[word2[i]-'a']++;
        }

        int count1=0, count2=0;
        for(int i=0;i<26;i++)
        {
            if(mp1[i]>0)    count1++;
            if(mp2[i]>0)    count2++;
        }
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
            {
                if(mp1[i]==0||mp2[j]==0)    continue;
                int a1=count1;
                int a2 = count2;

                if(mp1[i]==1)   a1--;
                mp1[i]--;
                if(mp2[j]==1)   a2--;
                mp2[j]--;
                if(mp1[j]==0)   a1++;
                mp1[j]++;
                if(mp2[i]==0)   a2++;
                mp2[i]++;

                if(a1==a2)  return true;

                mp1[i]++;
                
                mp2[j]++;
                
                mp1[j]--;
                
                mp2[i]--;

                
                
            }
        }

        return false;
    }
};