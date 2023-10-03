/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
}; 

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {
   public:
    int pathSum(TreeNode *root, int targetSum) {
        if (!root) return 0;
        return dfs(root, targetSum) + pathSum(root->left, targetSum) +
               pathSum(root->right, targetSum);
    }

   private:
    int dfs(TreeNode *root, long sum) {
        if (!root) return 0;
        return (sum == root->val) + dfs(root->left, sum - root->val) +
               dfs(root->right, sum - root->val);
    }
};
// @lc code=end
