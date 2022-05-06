#include<bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin>>n;
    string a,b;

    vector<int> ab, ba;

    cin>>a>>b;

    for(int i=0;i<n;i++)
    {
        if(a[i]=='a'&&b[i]=='b')
            ab.push_back(i+1);

        if(a[i]=='b'&&b[i]=='a')
            ba.push_back(i+1);
    }


    if((ab.size()+ba.size())%2==1)
    {
        cout<<-1<<endl;
        return 0;
    }

    cout<<(ab.size()+ba.size())/2+ab.size()%2<<endl;

   int x=ab.size();
    int y=ba.size();
    
    for(int i=1;i<x;i=i+2)
    {
        cout<<ab[i]<<' '<<ab[i-1]<<endl;
    }
    for(int i=1;i<y;i=i+2)
    {
        cout<<ba[i]<<' '<<ba[i-1]<<endl;
    }
    
    if(x%2==1)
    {
        
        cout<<ab.back()<<' '<<ab.back()<<endl;
        cout<<ba.back()<<' '<<ab.back()<<endl;
    }

    
}