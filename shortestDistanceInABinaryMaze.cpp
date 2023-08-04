#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int bfsApproach(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination)
    {
        if(source.first==destination.first&&source.second==destination.second)  return 0;
        
        vector<int> delrow={1,0,-1,0};
        vector<int> delcol={0,-1,0,1};

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n,0));

        queue<pair<int, pair<int, int>>> q;
        q.push({0,{source}});
        vis[source.first][source.second]=1;
        int ans =0;

        while(!q.empty())
        {
            auto it = q.front();
            int x = it.second.first;
            int y = it.second.second;
            int dis =it.first;
            q.pop();

            if(x==destination.first&&y==destination.second) return dis;
            for(int i=0;i<4;i++)
            {
                int newx = x+delrow[i];
                int newy = y+delcol[i];
                if(newy>=0&&newx>=0&&newx<m&&newy<n&&vis[newx][newy]==0&&grid[newx][newy]==1)
                {
                    q.push({dis+1,{newx,newy}});
                    vis[newx][newy]=1;
                }
            }

        }


        return -1;
    }
    int dijkstraApproach(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination)
    {
        if(source.first==destination.first&&source.second==destination.second)  return 0;
        
        vector<int> delrow={1,0,-1,0};
        vector<int> delcol={0,-1,0,1};

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dis(m, vector<int>(n,1e9));

        dis[source.first][source.second]=0;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0,{source}});

        while(!pq.empty())
        {
            auto it = pq.top();
            int x = it.second.first;
            int y = it.second.second;
            int distance =it.first;
            pq.pop();
            
            for(int i=0;i<4;i++)
            {
                int newx = x+delrow[i];
                int newy = y+delcol[i];
                if(newy>=0&&newx>=0&&newx<m&&newy<n&&grid[newx][newy]==1)
                {
                    if(distance+1<dis[newx][newy])
                    {
                        dis[newx][newy]=distance+1;
                        pq.push({distance+1,{newx,newy}});

                    }

                    
                }
            }
            
        }

        if(dis[destination.first][destination.second]!=1e9) return dis[destination.first][destination.second];
        

        return -1;

        

    }
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        
        // int ans = bfsApproach(grid, source, destination);
        int ans = dijkstraApproach(grid, source, destination);
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends