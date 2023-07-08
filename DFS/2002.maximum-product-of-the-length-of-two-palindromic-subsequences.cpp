/*
 * @lc app=leetcode id=2002 lang=cpp
 *
 * [2002] Maximum Product of the Length of Two Palindromic Subsequences
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProduct(string s) {
        // The idea is to check all scenarios using dfs where current value added to s1, s2
        // and not added to any
        string s1, s2;
        dfs(s, 0, s1, s2);
        return res;
    }
private:
    int res = 0;
    bool is_palin(string &str){
        int l = 0, r = str.size()-1;
        while(l <= r){
            if(str[l] != str[r])
                return false;
            l++, r--;
        } 
        return true;
    }
    void dfs(string &s, int idx, string &s1, string &s2) {
        if(idx >= s.size()) {
            if(is_palin(s1) && is_palin(s2)){
                res = max(res, int(s1.size()*s2.size()));
            }
            return;
        }
        s1.push_back(s[idx]);
        dfs(s, idx+1, s1, s2);
        s1.pop_back();

        s2.push_back(s[idx]);
        dfs(s, idx+1, s1, s2);
        s2.pop_back();

        dfs(s, idx+1, s1, s2);
    }
};
// @lc code=end

int main(){
    Solution solution;
    cout << solution.maxProduct("leetcodecom");
    return 0;
}
