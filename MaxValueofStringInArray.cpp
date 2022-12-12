#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int maxlen = 0;
        vector<int> val(strs.size(),0);

        for(int i=0;i<strs.size();i++)
        {
            for(int j=0;j<strs[i].size();j++)
            {
                if(!isdigit(strs[i][j]))
                {
                    val[i]=strs[i].size();
                    break;
                }
            }

            if(val[i]==0)
            {
                val[i]=stoi(strs[i]);
            }
        }


        for(int i=0;i<strs.size();i++)
        {
            maxlen=max(maxlen,val[i]);
        }

        return maxlen;
        
    }
};