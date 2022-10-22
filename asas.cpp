#include <bits/stdc++.h>
using namespace std;

long long aladeenIsBack(long long N, long long a[][3]){
    vector<long long> aa[3];
    vector<long long> d;
    for(long long i=0;i<N;i++)
    {
        long long q = a[i][0];
        long long w = a[i][1];

        long long e= a[i][2];
        d.push_back(a[i][0]);
        aa[0].push_back(q);
        aa[1].push_back(w);
        aa[2].push_back(e);
    }

    long long res=0;
    for(long long i=0;i<N;i++)
    {
    long long tt = 0;
    long long point =0;
    for(long long i=0;i<d.size();i++)
    {
        if(tt<d[i]){
            tt=max (tt,d[i]);
            point =i;
            
            }
    }
    res+=tt;
    d[point]=0;
    for(long long i=1;i<N-1;i++)
    {
        if(d[i-1]==0&&d[i+1]==0)
            d[i]=aa[i][2];
        else if(d[i-1]==0||d[i+1]==0)
            d[i]=aa[i][1];

    }
    if(point==0&&d[1]==0)
        d[point]=aa[0][1];

    if(point==N&&d[N-1]==0)
        d[point]=aa[N][1];

    }

    return res;
    
}


int main(){
    long long N;
    cin>>N;
    long long a[N+10][3];
    long long i, j;
    for(j=0;j<3;j++)
        for(i=1;i<=N;i++)
            cin >> a[i][j];
    cout<<aladeenIsBack(N, a)<<endl;
    return 0;
}