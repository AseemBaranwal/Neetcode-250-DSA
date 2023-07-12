/*
 * @lc app=leetcode id=1958 lang=cpp
 *
 * [1958] Check if Move is Legal
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        r = rMove;
        c = cMove;
        bool isWhite = color=='W';
        bool up = checkMoveUtil(board, rMove-1, cMove, !isWhite, -1, 0);
        bool down = checkMoveUtil(board, rMove+1, cMove, !isWhite, 1, 0);
        bool left = checkMoveUtil(board, rMove, cMove-1, !isWhite, 0, -1);
        bool right = checkMoveUtil(board, rMove, cMove+1, !isWhite, 0, 1);
        bool ul = checkMoveUtil(board, rMove-1, cMove-1, !isWhite, -1, -1);
        bool ur = checkMoveUtil(board, rMove-1, cMove+1, !isWhite, -1, 1);
        bool dl = checkMoveUtil(board, rMove+1, cMove-1, !isWhite, 1, -1);
        bool dr = checkMoveUtil(board, rMove+1, cMove+1, !isWhite, 1, 1);
        return up or down or left or right or ul or ur or dl or dr;
    }
private:
    int r, c;
    bool checkMoveUtil(vector<vector<char>>& board, int x, int y, bool cc, int dx, int dy){
        if(board[x][y] == '.' or outofBounds(board, x, y)) return false;
        char exColor = (cc ? 'W' : 'B');
        if(board[x][y] != exColor and board[x][y] != '.' and (outofBounds(board, x+dx, y+dy) or (board[x+dx][y+dy] == '.')) and ((x-r)>2 or (y-c)>2))
            return true;
        return checkMoveUtil(board, x+dx, y+dy, cc, dx, dy);
    }
    bool outofBounds(vector<vector<char>>& board, int x, int y) {
        return x < 0 or y < 0 or x >= board.size() or y >= board[0].size();
    }
};
// @lc code=end

