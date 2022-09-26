// { Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution {
  public:
    long long maximumMultiple(int N, int A[]) {
        // code here
        sort(A,A+N);
        int i,j;
        i=0;
        j=1;
        for(int i=0;i<N-1;i++)
        {
            if(A[j]>=0)
                break;
                
        }
        
        long long res=A[i]*A[j];
        return res;
        
        
    }
};


// { Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution obj;
        long long res = obj.maximumMultiple(N, A);

        cout << res << endl;
    }
}
  // } Driver Code Ends