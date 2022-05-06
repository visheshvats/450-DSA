#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int a, b;

    cin >> a >> b;

    int t;
    cin >> t;
    vector<double> tt;
    int ab = t;
    while (ab--)
    {
        double e;
        cin >> e;
        tt.push_back(e);
    }

    vector<double> aa;
    vector<double> bb;

    double sum = 0;
    for (int j = 0; j < a; j++)
    {
        sum = sum + tt[j];
        aa.push_back(sum/a);
    }

    for (int j = a; j < t; j++)
    {
        sum = sum + tt[j] - tt[j - a];
        aa.push_back(sum/a);
    }

    sum=0;
    for (int j = 0; j < b; j++)
    {
        sum = sum + tt[j];
        bb.push_back(sum/b);
    }

    for (int j = b; j < t; j++)
    {
        sum = sum + tt[j] - tt[j - b];
        bb.push_back(sum/b);
    }

    char res=a;
    if(bb[0]>aa[0])
    {
        res=b;
    }
    int count=0;

    for(int i=0;i<t;i++)
    {
        
        if(aa[i]>bb[i]&&res==b)
        {
            count++;
            res=a;
        }
        if(aa[i]<bb[i]&&res==a)
        {
            count++;
            res=b;
        }
    }
    
    cout<<count;






    return 0;
}