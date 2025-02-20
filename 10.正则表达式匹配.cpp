/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
#include <array>
#include <cstdio>
#include <string>
#include <utility>
#include <vector>
class Solution {
private:
public:
  bool isMatch(std::string str, std::string pattern) {
    str.insert(str.begin(), ' ');
    std::vector<std::string> patterns;
    patterns.emplace_back("");
    for (const auto &patternChar : pattern) {
      if (patternChar == '*') {
        patterns.back() += patternChar;
      } else {
        patterns.push_back(std::string{patternChar});
      }
    }
    std::array<std::array<bool, 21>, 21> dp{false};
    dp[0][0] = true;
    for (int j = 1; j < patterns.size(); j++) {
      for (int i = 0; i < str.size(); i++) {
        if (patterns[j].size() == 2) {
          for (; i < str.size(); i++) {
            dp[i][j] = dp[i][j - 1] || (i == 0 && j == 1) ||
                       (i != 0 &&
                        (patterns[j].front() == '.' ||
                         str[i] == patterns[j].front()) &&
                        dp[i - 1][j]);
            printf("dp[%d][%d]=%d\n", i, j, dp[i][j]);
          }
          break;
        }
        dp[i][j] =
            (i > 0) && dp[i - 1][j - 1] &&
            (patterns[j].front() == '.' || str[i] == patterns[j].front());

        printf("dp[%d][%d]=%d\n", i, j, dp[i][j]);
      }
    }
    return dp[str.size() - 1][patterns.size() - 1];
  }
};
// @lc code=end
