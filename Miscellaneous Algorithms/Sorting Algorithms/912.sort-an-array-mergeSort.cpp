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
        // Sorting it with the MergeSort for the first time and then will solve for heapSort
        int n = nums.size();
        mergeSort(nums, 0, n-1);
        return nums;
    }
private:
    void mergeSort(vector<int>& nums, int start, int end) {
        if(start < end){
            int mid = start + (end - start)/2;
            mergeSort(nums, start, mid);
            mergeSort(nums, mid+1, end);
            merge(nums, start, mid, end);
        }
    }
    void merge(vector<int> &nums, int start, int mid, int end){
        // Using i and j for the two halves of the arrays and the k will be used for the temp array
        int i = start, j = mid+1, k = 0;
        vector<int> temp(end-start+1);
        while(i <= mid and j <= end){
            if(nums[i] < nums[j])
                temp[k++] = nums[i++];
            else
                temp[k++] = nums[j++];
        }
        while(i <= mid)
            temp[k++] = nums[i++];
        while(j <= end)
            temp[k++] = nums[j++];
        for(int idx = 0; idx < k; idx++){
            nums[idx+start] = temp[idx];
        }
    }
};
// @lc code=end

