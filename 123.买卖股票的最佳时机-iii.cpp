/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

#include <algorithm>
#include <array>
#include <climits>
#include <cstdio>
#include <vector>
using namespace std;
// @lc code=start
// 需要使用动态规划
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    // 0 什么都没干
    // 1 买入
    // 2 然后卖出
    // 3 第二次
    // 4
    vector<array<int, 4>> dp(prices.size());
    dp[0] = {-prices[0], 0, -prices[0], 0};
    for (int i = 1; i < prices.size(); i++) {
      dp[i] = {
          max(-prices[i], dp[i - 1][0]),
          max(dp[i - 1][0] + prices[i], dp[i - 1][1]),
          max(dp[i - 1][2], dp[i - 1][1] - prices[i]),
          max(dp[i - 1][3], dp[i - 1][2] + prices[i]),
      };
      // printf("dp[%d] = {%d, %d, %d, %d}\n", i, dp[i][0], dp[i][1], dp[i][2],
      //        dp[i][3]);
    }
    return dp[prices.size() - 1].back();
  }
};
// @lc code=end
