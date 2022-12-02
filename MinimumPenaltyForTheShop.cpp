#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int score =0;
        int mxscore =0;
        int ind=-1;


        for(int i=0;i<customers.size();i++)
        {
            if(customers[i]=='Y')
            {
                score++;
            }
            else
            {
                score--;
            }
            if(score>mxscore)
            {
                ind =i;
                mxscore=score;
            }
        }


        return ind+1;
        
    }
};