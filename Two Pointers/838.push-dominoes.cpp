/*
 * @lc app=leetcode id=838 lang=cpp
 *
 * [838] Push Dominoes
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    string pushDominoes(string &dominoes) {
        // If we encounter . in string, we move forward to next index.
        // If we encounter L in string, we see if index of right is -1, we make all the left index L until we see any other L.
        // If we encounter L in string and there is some previous R index, then we simultaneously change string from left and right side till two pointers reach each other. After that right moves back to -1.
        // If we encounter R in string, we see if the index of R is not -1, we make all the indices upto that index R.
        int n = dominoes.size();
        int right = -1;
        for(int i = 0; i < n; i++) {
            if(dominoes[i] == 'L'){
                // find a right prior to it
                if(right == -1){
                    for(int j = i-1; j >= 0 and dominoes[j] == '.'; j--)
                        dominoes[j] = 'L';
                } else {
                    for(int j = right + 1, k = i-1; j < k; ++j, --k){
                        dominoes[j] = 'R';
                        dominoes[k] = 'L';
                    }
                    right = -1;
                }
            } else if (dominoes[i] == 'R') {
                if(right != -1){
                    for(int j = right + 1; j < i; j++)
                        dominoes[j] = 'R';
                }
                right = i;
            }
        }
        if(right != -1)
            for(int i = right+1; i < n; i++)
                dominoes[i] = 'R';
        return dominoes;
    }
};
// @lc code=end

