// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class t
{
    public:
        int v;
        int w;
        int r;

};

bool so(t a, t b)
{
    return (a.v>b.v);
}


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here

        double profit=0;

        vector<int> r(n,0);
        for(int i=0;i<n;i++)
        {
            r[i]=(arr[i].value/arr[i].weight);

        }

        vector<t> tt;

        for(int i=0;i<n;i++)
        {
            t a;
            a.r=r[i];
            a.v=arr[i].value;
            a.w=arr[i].weight;

            tt.push_back(a);

        }

        sort(tt.begin(),tt.end(),so);

        for(int i=0;i<n;i++)
        {
            if(tt[i].w<W)
            {
                W-=tt[i].w;
                profit+=tt[i].v;

            }

            else if(tt[i].w>W)
            {
                profit=profit+(((tt[i].v)/(double)tt[i].w)*(double)W);
            }
        }

        return profit;



    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends