#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void solve(int col, vector<string> & board, vector<vector<string>> & ans, int n, vector<int> &rowhash,
      vector<int> &upperdiagonalhash,
      vector<int> &lowerdiagonalhash) {
      if (col == n) {
        ans.push_back(board);
        return;
      }
      for (int row = 0; row < n; row++) {
        if (rowhash[row]!=1&& lowerdiagonalhash[row+col]==0&&upperdiagonalhash[n-1+col-row]==0) {
          board[row][col] = 'Q';
          rowhash[row]=1;
          lowerdiagonalhash[row+col]=1;
          upperdiagonalhash[n-1+col-row]=1;
          solve(col + 1, board, ans, n, rowhash, upperdiagonalhash, lowerdiagonalhash);
          rowhash[row]=0;
          lowerdiagonalhash[row+col]=0;
          upperdiagonalhash[n-1+col-row]=0;
          board[row][col] = '.';
        }
      }
    }

  public:
    vector<vector<string>> solveNQueens(int n) {
      vector<vector<string>> ans;
      vector<string> board(n);
      string s(n, '.');
      vector<int> rowhash(n,0);
      vector<int> upperdiagonalhash(2*n-1,0);
      vector<int> lowerdiagonalhash(2*n-1,0);

      for (int i = 0; i < n; i++) {
        board[i] = s;
      }
      solve(0, board, ans, n, rowhash, upperdiagonalhash, lowerdiagonalhash);
      return ans;
    }
};