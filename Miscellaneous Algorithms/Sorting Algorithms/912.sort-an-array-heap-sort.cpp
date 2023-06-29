/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // Solving it using Heap Sort after solving already with merge Sort
        int n = nums.size();
        for(int i = n/2-1; i >= 0; i--)
            heapify(nums, n, i);
        
        for(int i = n-1; i > 0; i--){
            swap(nums[i], nums[0]);
            heapify(nums, i, 0);
        }
        return nums;
    }
private:
    void heapify(vector<int>& nums, int n, int i){
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;
        if(left < n and nums[left] > nums[largest])
            largest = left;
        if(right < n and nums[right] > nums[largest])
            largest = right;
        if(largest != i){
            swap(nums[i], nums[largest]);
            heapify(nums, n, largest);
        }
    }
};
// @lc code=end

