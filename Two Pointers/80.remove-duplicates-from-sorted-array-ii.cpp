// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem80.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Avoid Stephen Pochman solution [NOT O(1)]
        // Keep two pointers whenever dealing with duplicates. Place them and 
        // move only when you find that a match has been found
        int i = 1, j = 1;
        int cnt = 1;
        while(j < nums.size()){
            if(nums[j] != nums[j-1]){
                // No duplicate found and first instance of nums[j]
                nums[i++] = nums[j];
                cnt = 1;
            }else{
                // Duplicate found and check if 2 are already found
                if(cnt < 2){
                    nums[i++] = nums[j];
                    cnt = 2;
                }
            }
            j++;
        }
        return i;
    }
};
// @lc code=end

