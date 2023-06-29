/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 2 conditions to check:
        // 1. No same numbers in rows and columns
        // 2. No same number in the 3*3 grid

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board.size(); j++){
                if(board[i][j] == '.') continue;
                // Checking in the column
                for(int k = 0; k < board[0].size(); k++)
                    if(j != k and board[i][j] == board[i][k]) 
                        return false;
                // Checking in the row
                for(int k = 0; k < board.size(); k++)
                    if(i != k and board[i][j] == board[k][j])
                        return false;
                // Checking in the grid
                int x = i/3*3, y = j/3*3;
                for(int k = x; k < x+3; k++)
                    for(int l = y; l < y+3; l++)
                        if(k != i and j != l and board[k][l] == board[i][j])
                            return false;
                    
            }
        }
        return true;
    }
};
// @lc code=end

