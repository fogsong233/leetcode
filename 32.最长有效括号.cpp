/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  int longestValidParentheses(string s) {
    vector<int> dp(s.size(), 0);
    int maxLength = 0;
    for (int i = 1; i < s.size(); i++) {
      if (s[i] == '(') {
        continue;
      }
      if (s[i - 1] == '(') {
        dp[i] = (i - 2 >= 0) ? dp[i - 2] + 2 : 2;
      } else {
        dp[i] = (i - dp[i - 1] - 1 >= 0) && (s[i - dp[i - 1] - 1] == '(')
                    ? dp[i - 1] + 2 +
                          (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0)
                    : 0;
      }
      maxLength = max(dp[i], maxLength);
    }
    return maxLength;
  }
};
// @lc code=end
