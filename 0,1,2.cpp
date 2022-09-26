
#include<bits/stdc++.h>

using namespace std;



void sort012(int a[], int n)
{
    int s=0;
    int m=0;
    int l= n-1;

    while(m<=l)
    {
        if(a[m]==0)
        {a
            swap(a[s],a[m]);
            s++;
            m++;

        }

        else if(a[m]==1)
        {
            m++;
        }

        else if(a[m]==2)
        {
            swap(a[m],a[l]);
            l--;
            

        }
    }
    
}


int main() {

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d", &arr[i]);
        }

        sort012(arr, n);

        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    return 0;
}
