/*
 * @lc app=leetcode id=605 lang=cpp
 *
 * [605] Can Place Flowers
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // We just need to check whether the flowerbed has space at the location to the left
        // and to the right of the flowerbed. If it is true, we just use it directly and then
        // move on to the next index. 
        // DO NOT TRY TO OPTIMIZE BEFORE WRITING THE ORIGINAL SIMPLE SOLUTION!!!

        int size = flowerbed.size();
        for(int i = 0; i < size and n>0; i++) {
            if(flowerbed[i] == 0){
                // Space is available at current location
                int leftEmpty = (i == 0) or (flowerbed[i-1] == 0);
                int rightEmpty = (i == size - 1) or (flowerbed[i+1] == 0);

                if(leftEmpty and rightEmpty){
                    n--;
                    flowerbed[i] = 1;
                }
            }
        }
        return n==0;
    }
};
// @lc code=end

