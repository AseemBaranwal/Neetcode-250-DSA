/*
 * @lc app=leetcode id=357 lang=cpp
 *
 * [357] Count Numbers with Unique Digits
 */

// @lc code=start
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        // For every new number, we are left with one less digit to use permutations
        // 9 * 9 for first time because we can't place 0 in the first digit, but afterwards we
        // can use it
        // We see that f[0] = 1, f[1] = 10, and then f[2] = 9*9 + f[1], f[3] = 9*8*7 + f[2]
        if(n == 0) return 1;
        int availableNum = 9;
        int uniqueNumber = 9;
        int res = 10;
        while(n-- > 1 and availableNum > 0){
            uniqueNumber *= availableNum;
            availableNum--;
            res += uniqueNumber;
        }
        return res;
    }
};
// @lc code=end

