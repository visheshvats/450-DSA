// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

bool so(Job a, Job b)
    {
        if(a.profit>b.profit)
            return true;

        else
            return false;
    }
    

class Solution 
{
    public:

    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        int maxx=0;

        for(int i=0;i<n;i++)
        {
            maxx=max(maxx,arr[i].dead);
        }

        vector<int> res(n+1,-1);

        sort(arr,arr+n,so);
        int countjob=0;
        int profit=0;


        for(int i=0;i<n;i++)
        {
            for(int j=arr[i].dead;j>0;j++)
            {
                if(res[j]==-1)
                {
                    countjob++;
                    profit+=arr[i].profit;
                    res[j]=arr[i].id;
                    break;

                }
            }

        }

        vector<int>re;
        re.push_back(countjob);
        re.push_back(profit);


        return re;







    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends