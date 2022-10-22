#include<bits/stdc++.h>
using namespace std;

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dis(n, vector<int> (n, int(1e6)));   
        for(int i=0; i<n; i++)      
            dis[i][i]=0;
        
        for(auto edge : edges){     
            int u=edge[0], v=edge[1], w=edge[2];
            dis[u][v]=dis[v][u]=w;
        }
        
        for(int k=0; k<n; k++)
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    if(dis[i][j]>dis[i][k]+dis[k][j])       
                        dis[i][j]=dis[i][k]+dis[k][j];      
         
        int ans=0, ans_count=n;
        for(int i=0; i<n; i++){         
            int count=0;
            for(int j=0; j<n; j++)      
                if(dis[i][j]<=distanceThreshold)        
                    count++;
    
            if(count<=ans_count){       
                ans_count=count;
                ans=i;
            }
        }
        
        return ans;         
    }

int findBestCity(int distanceThreshold, int city_nodes, vector<int> city_from, vector<int> city_to, vector<int> city_weight)
{
    vector<vector<int>> edges;
    for(int i=0;i<city_from.size();i++)
    {
        int a = city_from[i];
        int b = city_to[i];
        int c = city_weight[i];
        vector<int> aa;
        aa.push_back(a);
        aa.push_back(b);
        aa.push_back(c);

        edges.push_back(aa);

        
    }


    int res = findTheCity(city_from.size(), edges, distanceThreshold);

    return res;
}