/*
 * @lc app=leetcode id=535 lang=cpp
 *
 * [535] Encode and Decode TinyURL
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
    // Using birectional hashmaps to store the solution from URL to code and from code to URL
public:
    int val = 0;
    unordered_map<string, string> urlToCode;
    unordered_map<string, string> codeTourl;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortURL = "https://tinyurl.com/" + to_string(val);
        urlToCode[longUrl] = shortURL;
        codeTourl[shortURL] = longUrl;
        val++;
        return shortURL;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return codeTourl[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
// @lc code=end

