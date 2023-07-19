/*
 * @lc app=leetcode id=779 lang=cpp
 *
 * [779] K-th Symbol in Grammar
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int kthGrammar(int n, int k) {
        vector<int> arr{0, 0, 1};
        bool opposite = false;
        while(k >= 2){
            if(k%2 == 0) opposite = !opposite;
            k = (k+1)/2;
        }
        int res = arr[k];
        if(opposite){
            return res == 0 ? 1 : 0;
        }
        return res;
    }
};
// @lc code=end

