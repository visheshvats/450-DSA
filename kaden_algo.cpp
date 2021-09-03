// C++ program to print largest contiguous array sum
#include<iostream>
#include<climits>
using namespace std;

int maxSubArraySum(int a[], int n)

{
	int max_so_far=0;
    int max_till_here=0;
    for(int i=0;i<n;i++)
    {
        max_till_here +=a[i];
        if(max_till_here>max_so_far)
        {
            max_so_far=max_till_here;
        }
        else if(max_till_here<0)
        {
            max_till_here=0;
        }
    }

    return max_so_far;
}

/*Driver program to test maxSubArraySum*/
int main()
{
	int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int n = sizeof(a)/sizeof(a[0]);
	int max_sum = maxSubArraySum(a, n);
	cout << "Maximum contiguous sum is " << max_sum;
	return 0;
}
