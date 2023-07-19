/*
 * @lc app=leetcode id=2215 lang=cpp
 *
 * [2215] Find the Difference of Two Arrays
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> arr1, arr2;
        for(int &x: nums1) arr1.insert(x);
        for(int &x: nums2) arr2.insert(x);
        for(int &x: nums2){
            if(arr1.find(x) != arr1.end())
                arr1.erase(x);
        }
        for(int &x: nums1){
            if(arr2.find(x) != arr2.end())
                arr2.erase(x);
        }
        vector<vector<int>> res(2);
        for(auto &val: arr1) res[0].push_back(val);
        for(auto &val: arr2) res[1].push_back(val);
        return res;
    }
};
// @lc code=end

