#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(vector<vector<char>> &board, int row, int col, char i)
    {
        for(int j=0;j<9;j++)
        {
            //row check
            if(board[row][j]==i)
                return false;

            //col
            if(board[j][col]==i)
                return false;


            //block check
            if(board[3*(row/3)+j/3][3*(col/3)+j%3]==i)
                return false;

        }
            return true;
    }
    bool solve(vector<vector<char>>& board)
    {
        for(int row=0;row<9;row++)
        {
            for(int col =0;col<9;col++)
            {
                if(board[row][col]=='.')
                {
                    for(char i='1';i<='9';i++)
                    {
                        if(isValid(board, row, col, i))
                        {
                            board[row][col]=i;
                            if(solve(board))
                                return true;
                            else
                                board[row][col]='.';

                        }
                    }
                return false;
                } 
                    
            }
        }

        return true;

    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        
    }
};