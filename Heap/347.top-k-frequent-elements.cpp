/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Using a hashmap and a priority queue in this case.
        // Hashmap will be used to regularly count the instances of occurrences
        // Priority Queue/Heap will be used to get the complexity to O(N log K).
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        unordered_map<int, int> cnt;
        for(int &x : nums) cnt[x]++;
        for(auto &pp: cnt){
            pq.push({pp.second, pp.first});
            if(pq.size() > k)
                pq.pop();
        }
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
// @lc code=end

