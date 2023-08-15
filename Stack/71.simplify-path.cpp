/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    string simplifyPath(string path) {
        // Pop elements from stack whenever you see a folderName enclosed within
        // "/../"
        string res, temp;
        vector<string> st;
        stringstream ss(path);
        while (getline(ss, temp, '/')) {
            if (temp == "." or temp == "") continue;
            if (!st.empty() and temp == "..")
                st.pop_back();
            else if (temp != "..")
                st.push_back(temp);
        }
        for (string curr : st) res += "/" + curr;
        return res.empty() ? "/" : res;
    }
};
// @lc code=end
