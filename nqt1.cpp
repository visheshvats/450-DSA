#include<iostream>
#include<vector>

using namespace std;

int main(void)


{

    int a;
    cin>>a;
    int b=a;
    vector<int> aa;
    while(b--)
    {
        int temp;
        cin>>temp;
        aa.push_back(temp);

    }


    int res=0;

    for(int i=0;i<a-1;i++ )
    {
        if(aa[i]<aa[i+1])
            res=1;
        else if(aa[i+1]<aa[i])
            {
                cout<<"No";
                return 0;
            }
    }


    if(res==0)
    {
        cout<<"No";
    }
    else
    {
        cout<<"yes";
    }


    return 0;
}