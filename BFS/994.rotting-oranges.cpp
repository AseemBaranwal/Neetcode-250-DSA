
/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int> dir{0, 1, 0, -1, 0};
        int freshCnt = 0;
        queue<pair<int, int>> Q;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 2){
                    Q.push({i, j});
                }else if(grid[i][j] == 1) freshCnt++;
            }
        }
        if(freshCnt == 0) return 0;
        int mins = 0;
        while(!Q.empty()){
            int k = Q.size();
            mins++;
            for(int i = 0; i < k; i++){
                auto curr = Q.front(); Q.pop();
                for(int j = 0; j < 4; j++){
                    int newX = curr.first + dir[j];
                    int newY = curr.second + dir[j+1];
                    if(isValid(grid, newX, newY)){
                        grid[newX][newY] = 2;
                        freshCnt--;
                        Q.push({newX, newY});
                    }
                }
            }
            if(freshCnt == 0) return mins;
        }
        return -1;
    }
private:
    inline bool isValid(vector<vector<int>>& grid, int x, int y){
        return x >= 0 and x < grid.size() and y >= 0 and y < grid[0].size() and grid[x][y] == 1;
    }
};
// @lc code=end

