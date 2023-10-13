#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int energyCost(vector<int> stair, int k) {
    vector<int> dp(stair.size() + 1, INT_MAX);
    dp[0] = 0;
    int n = stair.size();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                dp[i] = min(dp[i], dp[i - j] + abs(stair[i] - stair[i - j]));
            }
        }
    }
    return dp[n];
}