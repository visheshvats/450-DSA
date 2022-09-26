#include<bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin>>n;
    vector<int> aa;
    while (n--)
    {
        int t;
        cin>>t;
        aa.push_back(t);
    }
    

    int flag =0;

    for(int i=0;i<=(1<<n)-1;i++)
    {
        int sum = 0;

        for(int j=0;j<=n-1;j++)
        {
            if(i&(1<<j))
            {
                sum = sum + aa[j];
            }
            else
            {
                sum = sum - aa[j];
            }
        }

        if(sum%360 == 0)
        {
            cout<<"Yes";
            return 0;


        }

    }

    cout<<"NO";
    return 0;



    

    

}