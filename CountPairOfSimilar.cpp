#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool ischeck(string a, string b)
    {
        map<char, bool> occur1;
        for (int i = 0; i < a.length(); i++)
        {
            occur1[a[i]] = 1;
        }
        map<char, bool> occur2;
        for (int i = 0; i < b.length(); i++)
        {
            occur2[b[i]] = 1;
        }
        if (occur1 == occur2)
            return true;
        else
            return false;
    }
    int similarPairs(vector<string> &words)
    {
        int a = 0;

        vector<map<char, bool>> aa;
        for (int i = 0; i < words.size(); i++)
        {
            map<char, bool> occur1;
            for (int j = 0; j < words[i].length(); j++)
            {
                occur1[words[i][j]] = 1;
            }
            aa.push_back(occur1);
        }


        for (int i = 0; i < aa.size(); i++)
        {
            for (int j = i + 1; j < aa.size(); j++)
            {
                if(aa[i]==aa[j])
                    a++;
            }
        }

        return a;
    }
};