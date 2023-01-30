#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<int, int> coordinate(int n, int a)
    {
        int x = ((n*n)-a)/n;
        int y;
        if(x%2==0)
        {
            y= (a%n)-1;
        }
        else
        {
            y = n - (a%n);
        }
        return {x,y};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        queue<pair<int, int>> q; //<square, move>
        q.push({1,0});
        vector<int> vis(n*n,0);

        while(!q.empty())
        {
            auto it =q.front();
            int moves=it.second;
            int squ = it.first;
            q.pop();
            for(int i=1;i<=6&&squ+i<=n*n;i++)
            {
                int nn = squ+i;
                int x = coordinate(n,nn).first;
                int y = coordinate(n,nn).second;
                if(board[x][y]!=-1) nn = board[x][y];
                if(vis[nn-1]==0)
                {
                    if(nn==n*n)
                    {
                        return moves+1;
                    }
                    q.push({nn,moves+1});
                }
            }
        }

        return -1;
        


        
    }
};