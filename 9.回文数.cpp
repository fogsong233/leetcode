/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
#include <cstdio>
class Solution {
public:
  bool isPalindrome(int x) {
    int y = 0;
    if (x < 0)
      return false;
    if (x < 100)
      return x < 10 || !bool(x % 11);
    if (!(x % 10))
      return false;
    while (x >= y) {
      if (x == y || (x >= 10 && x / 10 == y))
        return true;
      y = y * 10 + (x % 10);
      x /= 10;
    }
    return false;
  }
};
// @lc code=end
