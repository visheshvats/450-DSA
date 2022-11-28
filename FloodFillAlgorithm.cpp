//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(int sr, int sc, vector<vector<int>> &image, int newColor, int ini,
     vector<vector<int>> &ans, vector<int> &delrow, vector<int> &delcol, int n, int m)
    {
        ans[sr][sc]=newColor;

        for(int i=0;i<4;i++)
        {
            int srr = sr+delcol[i];
            int scc = sc +delrow[i];

            if(srr<n&&srr>=0&&scc>=0&&scc<m&&image[srr][scc]==ini&&ans[srr][scc]!=newColor)
            {
                dfs(srr, scc, image, newColor, ini, ans, delrow, delcol, n, m);
            }
            
        }




    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        vector<vector<int>> ans = image;
        int ini = image[sr][sc];
        vector<int> delrow = {0,-1, 0,1};
        vector<int> delcol = {1,0, -1,0};
        int n = image.size();
        int m = image[0].size();


        
        dfs(sr, sc, image, newColor,ini, ans, delrow, delcol, n, m);

        return ans;

    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends