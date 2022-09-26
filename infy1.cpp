#include<bits/stdc++.h>
using namespace std;
unsigned long int catalanDP(unsigned int n)
{
    // Table to store results of subproblems
    unsigned long int catalan[n + 1];
 
    // Initialize first two values in table
    catalan[0] = catalan[1] = 1;
 
    // Fill entries in catalan[] using recursive formula
    for (int i = 2; i <= n; i++) {
        catalan[i] = 0;
        for (int j = 0; j < i; j++)
            catalan[i] += catalan[j] * catalan[i - j - 1];
    }
 
    // Return last entry
    return catalan[n];
}
 

int main(void)
{
    int n;
    int t;
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        int tt;
        cin>>tt;
        arr.push_back(tt);

    }

    stack<int> sForward, sBackward;

	
	int ans = -1;

	for (int i = 0; i < n; i++) {

		
		while (!sForward.empty()
			&& arr[i] < arr[sForward.top()]) {
			ans = max(ans, arr[i] ^ arr[sForward.top()]);
			sForward.pop();
		}
		sForward.push(i);

		
		while (!sBackward.empty()
			&& arr[n - i - 1] < arr[sBackward.top()]) {
			ans = max(ans, arr[n - i - 1] ^ arr[sBackward.top()]);
			sBackward.pop();
		}

		sBackward.push(n - i - 1);
	}

    ans=t*catalanDP(ans);


    cout<<ans<<endl;

    


    return 0;
}