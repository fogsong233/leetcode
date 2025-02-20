/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
#include <cstdint>
class Solution {
public:
  int myAtoi(string s) {
    long res = 0;
    int i = -1;
    while (s[++i] == ' ') {
    }
    bool isNeg = false;
    if (s[i] == '-' || s[i] == '+') {
      isNeg = s[i] == '-';
      ++i;
    }
    for (; i < s.size() && (s[i] - '0') < 10 && s[i] - '0' >= 0; ++i) {
      res = res * 10 + (s[i] - '0');
      if (!isNeg && res >= INT32_MAX) {
        return INT32_MAX;
      }
      if (isNeg && -res <= INT32_MIN) {
        return INT32_MIN;
      }
    }
    return res * (isNeg ? -1 : 1);
  }
};

// @lc code=end
