#include <bits/stdc++.h>
using namespace std;

bool ss(int a, int b)
{
    if (a < b)
        return true;

    else
        return false;
}

int main(void)
{
    int n = 5;
    vector<int> aa = {1, 2, 232, 24, 565};

    sort(aa.begin(), aa.end(), ss);

    for (int i = 0; i < n; i++)
    {
        cout<<aa[i]<<" ";
    }


    return 0;
}