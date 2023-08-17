/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // We will use the Monotonic Stack to find where is the next greatest element
        // Precomputing the next greatest element helps in finding the value in O(1)
        // Using a hashmap to find the index of some particular element of nums2 in nums1

        vector<int> nextBig = findNextBigElementVal(nums2);
        vector<int> res;
        unordered_map<int, int> idxMap;
        for(int i = 0; i < nums2.size(); i++){
            idxMap[nums2[i]] = i;
        }
        for(int &x: nums1){
            res.push_back(nextBig[idxMap[x]]);
        }
        return res;
    }
private:
    vector<int> findNextBigElementVal(vector<int> &nums){
        int n = nums.size(), idx = n-1;
        vector<int> res(n);
        stack<int> st;
        while(idx >= 0){
            while(!st.empty() and st.top() <= nums[idx]) {
                st.pop();
            }
            if(st.empty()){
                res[idx] = -1;
            }else{
                res[idx] = st.top();
            }
            st.push(nums[idx]);
            idx--;
        }
        return res;
    }
};
// @lc code=end

