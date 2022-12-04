#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();
        int a=-1;
        int b=0;
        int c=1;
        while(b<n)
        {
            if(sentence[b]==' ')
            {
                if(sentence[a]!=sentence[c])
                    return false;
            }
            a++;
            b++;
            c++;

        }

        if(sentence[n-1]!=sentence[0])
            return false;
        else
            return true;
        
    }
};