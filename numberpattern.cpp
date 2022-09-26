#include<iostream>

using namespace std;


int main()
{
    int i,j,row;

    cin>>row;

    for(i=1;i<=row;i++)
    {
        

        for(j=1;j<=i;j++)
        {
            cout<<j;
        }

        for(j=i-1;j>=1;j--)
        {
            cout<<j;
        }
        cout<<endl;
    }

    return 0;
}