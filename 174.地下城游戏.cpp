/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 */

#include <climits>
#include <cstdio>
#include <ranges>
#include <vector>
using namespace std;
// @lc code=start
#include <memory>
class Solution {
public:
  int calculateMinimumHP(vector<vector<int>> &dungeon) {
    int m = dungeon.size();
    int n = dungeon.front().size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
    dp[m - 1][n] = dp[m][n - 1] = 1;
    for (int i = m - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        dp[i][j] = max(min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j], 1);
      }
    }
    return dp[0][0];
  }
};
// @lc code=end
