/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

#include <algorithm>
#include <cstdio>
using namespace std;
// @lc code=start
class Solution {
public:
  int com(int bottom, int top) {
    long long ans = 1;
    for (int x = bottom - top + 1, y = 1; y <= top; x++, y++) {
      ans = ans * x / y;
    }
    return ans;
  }
  int uniquePaths(int m, int n) { return com(n + m - 2, min(m, n) - 1); }
};
// @lc code=end
