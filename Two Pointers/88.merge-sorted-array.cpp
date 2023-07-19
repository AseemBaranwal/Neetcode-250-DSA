/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int end = m+n-1;
        int first = m-1, second = n-1;
        while(first >= 0 and second >= 0){
            if(nums1[first] > nums2[second])
                nums1[end] = nums1[first--];
            else
                nums1[end] = nums2[second--];
            end--;
        }
        while(first >= 0){
            nums1[end--] = nums1[first--];
        }
        while(second >= 0){
            nums1[end--] = nums2[second--];
        }
    }
};
// @lc code=end

