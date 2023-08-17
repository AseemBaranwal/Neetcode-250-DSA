/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    string decodeString(string s) {
        // Use two stacks and push the characters into a stack until you
        // encounter a closing bracket. When we get closing bracket, multiply
        // the character that you have at the top by the value at the top of
        // integer stack and then push it again on the stack. At the end, pop
        // all the values from the stack and then reverse the string
        string res;
        int idx = 0, n = s.size();
        stack<char> stStr;
        stack<int> stCnt;
        while (idx < n) {
            if (isdigit(s[idx])) {
                auto val = find_number(s, idx);
                stCnt.push(val.first);
                idx += val.second;
            } else if (s[idx] != ']') {
                stStr.push(s[idx++]);
            } else if (s[idx] == ']') {
                //  closing here
                string temp;
                while (!stStr.empty() and stStr.top() != '[') {
                    temp += stStr.top();
                    stStr.pop();
                }
                reverse(temp.begin(), temp.end());
                stStr.pop();  // Opening popped
                int cnt = stCnt.top();
                stCnt.pop();
                string curr;
                for (int i = 0; i < cnt; i++) curr += temp;
                for (char ch : curr) stStr.push(ch);
                idx++;  // closing traversed
            }
        }
        while (!stStr.empty()) {
            res += stStr.top();
            stStr.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }

   private:
    pair<int, int> find_number(string &s, int idx) {  // {value, size}
        string num;
        while (idx < s.size() and isdigit(s[idx])) {
            num += s[idx++];
        }
        return {stoi(num), num.size()};
    }
};

// @lc code=end

// int main() {
//     string curr = "3[a2[c]]";
//     cout << Solution().decodeString(curr) << endl;
//     cout << Solution().decodeString("3[a]2[bc]") << endl;
//     cout << Solution().decodeString("2[abc]3[cd]ef") << endl;
//     return 0;
// }