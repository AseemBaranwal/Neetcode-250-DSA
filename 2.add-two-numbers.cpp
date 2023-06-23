// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem2.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry = 0) {
        // Base Case1
        if(!l1 and !l2){
            // Edge case
            if(carry){
                ListNode *ptr = new ListNode(carry);
                return ptr;
            }else return nullptr;
        }
        // Base case 2
        if(!l1 or !l2){
            int sum = (l1?l1->val:l2->val) + carry;
            int currentNum = sum%10;
            carry = sum/10;
            ListNode *currentNode = new ListNode(currentNum);
            if(l1)
                currentNode->next = addTwoNumbers(l1->next, l2, carry);
            else
                currentNode->next = addTwoNumbers(l1, l2->next, carry);
            return currentNode;
        }
        // Recurrence Relation
        int sum = l1->val + l2->val + carry;
        int currentNum = sum%10;
        carry = sum/10;
        ListNode *currentNode = new ListNode(currentNum);
        currentNode->next = addTwoNumbers(l1->next, l2->next, carry);
        return currentNode;
    }
};
// @lc code=end

