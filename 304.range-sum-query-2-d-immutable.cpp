/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size(), n = m>0 ? matrix[0].size() : 0;
        preSum = vector<vector<int>>(m, vector<int> (n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                preSum[i][j] += (i-1 >= 0 ? preSum[i-1][j]: 0);
                preSum[i][j] += (j-1 >= 0 ? preSum[i][j-1]: 0);
                preSum[i][j] -= ((i-1>= 0 and j-1 >= 0) ? preSum[i-1][j-1]: 0);
                preSum[i][j] += matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        bool rowPresent = row1-1>=0, colPresent = col1-1>=0;
        if(rowPresent and colPresent)
            return preSum[row2][col2] - preSum[row1-1][col2] - preSum[row2][col1-1] + preSum[row1-1][col1-1];
        if(rowPresent)
            return preSum[row2][col2] - preSum[row1-1][col2];
        if(colPresent)
            return preSum[row2][col2] - preSum[row2][col1-1];
        return preSum[row2][col2];
    }
private:
    vector<vector<int>> preSum;
    int m, n;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

