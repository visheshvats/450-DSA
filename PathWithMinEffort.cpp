#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();

        vector<int> delrow={1,0,-1,0};
        vector<int> delcol={0,-1,0,1};

        vector<vector<int>> dis(m, vector<int> (n, 1e9));
        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        dis[0][0]=0;
        pq.push({0,{0,0}});

        

        while(!pq.empty())
        {
            auto it = pq.top();
            int distance = it.first;
            int x = it.second.first;
            int y = it.second.second;
            pq.pop();

            for(int i=0;i<4;i++)
            {
                int newx = x+delrow[i];
                int newy = y+delcol[i];
                if(newx>=0&&newy>=0&&newx<m&&newy<n)
                {
                    if(dis[newx][newy]>max(distance,abs(arr[x][y]-arr[newx][newy])))
                    {
                        dis[newx][newy]=max(distance,abs(arr[x][y]-arr[newx][newy]));
                        pq.push({dis[newx][newy],{newx,newy}});
                    }

                }
            }

        }








        return dis[m-1][n-1];
        
    }
};