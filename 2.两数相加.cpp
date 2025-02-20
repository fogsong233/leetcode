/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start

//   Definition for singly-linked list.
// struct ListNode {
//   int val;
//   ListNode *next;
//   ListNode() : val(0), next(nullptr) {}
//   ListNode(int x) : val(x), next(nullptr) {}
//   ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

#include <iostream>
class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    auto *res_ln = new ListNode();
    auto *now_ln = res_ln;
    ListNode *l1_ptr = l1;
    ListNode *l2_ptr = l2;
    int next_digit = 0;
    while (true) {
      int add_val = next_digit + ((l1_ptr == nullptr) ? 0 : l1_ptr->val) +
                    ((l2_ptr == nullptr) ? 0 : l2_ptr->val);
      std::cout << add_val << std::endl;
      now_ln->val = add_val % 10;
      next_digit = add_val / 10;
      if (l1_ptr != nullptr) {
        l1_ptr = l1_ptr->next;
      }
      if (l2_ptr != nullptr) {
        l2_ptr = l2_ptr->next;
      }
      if (l1_ptr == nullptr && l2_ptr == nullptr) {
        break;
      }
      now_ln->next = new ListNode();
      now_ln = now_ln->next;
    }
    if (next_digit != 0) {
      now_ln->next = new ListNode(next_digit);
    }
    return res_ln;
  }
};
// @lc code=end
