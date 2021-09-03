#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int n=7;
	int x[7] = {5, 6, 9, 11, 12, 16, 20};
	int l[7] = {2, 3, 1, 5, 3, 1, 1};
	int h = 0;
	h = max(x[0] + 1, x[0] + l[0]);
    int res[7]={0,0,0,0,0,0,0};
    
	
	for(int i = 0; i < n; i++)
	{
		if (h >= x[i])
		{
			h = max(h,x[i]+l[i]);
		}
		else
		{
			for(int j=i;res[j]!=0;j--)
            {
                res[j]=h;
            }
            h=x[i]+l[i];
		}
	}

    if(res[n]==0)
    {
        for(int j=n;res[j]!=0;j--)
        {
            res[j]=h;
        }
    }


    //return res ki array karni hai


	

	return 0;
}