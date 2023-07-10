/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
bool sortMe(string &s1, string &s2){
    return s1 + s2 > s2 + s1;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // We use sorting in such a way that we try to compare whether AB is greater than BA
        // We sort the array keeping in mind that the original arrays might have all zeros and
        // hence we remove the values from the array beginning which are zeros.
        vector<string> arr;
        for(int &x: nums) arr.push_back(to_string(x));
        sort(arr.begin(), arr.end(), sortMe);
        string res;
        for(string &str: arr) res += str;
        while(res[0] == '0' and res.size() > 1)
            res.erase(0, 1);
        return res;
    }
};
// @lc code=end

