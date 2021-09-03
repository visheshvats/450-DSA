// { Driver Code Starts
//Initial Template for C

#include <stdio.h>


 // } Driver Code Ends
//User function Template for C


//Function to return a list of integers denoting spiral traversal of matrix. 
int* spirallyTraverse(int r, int c, int matrix[][c])
{   
    
}

// { Driver Code Starts.

int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int r, c;
		scanf("%d", &r);
		scanf("%d", &c);
		int matrix[r][c];
	 
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				scanf("%d", &matrix[i][j]);
			}
		}
		
		int *result = spirallyTraverse(r, c, matrix);
		for(int i = 0; i < r*c; i++)
			printf("%d ", result[i]);
		printf("\n");
	}
	return 0;
}  // } Driver Code Ends