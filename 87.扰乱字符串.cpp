/*
 * @lc app=leetcode.cn id=87 lang=cpp
 *
 * [87] 扰乱字符串
 */

#include <cstdio>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  bool isScramble(string s1, string s2) {
    if (s1.size() == 1) {
      return s1 == s2;
    }

    /**
     * @brief dp[len][i][j],
     * is that s1[i...i + len-1] and s2[j...j + len -1] can be transform
     */
    bool dp[31][30][30]{false};
    for (int len = 1; len <= s1.size(); len++) {
      for (int i = 0; i <= s1.size() - len; i++) {
        for (int j = 0; j <= s1.size() - len; j++) {
          if (len == 1) {
            dp[len][i][j] = s1[i] == s2[j];
            continue;
          }
          // split
          for (int k = 1; k <= len; k++) {
            dp[len][i][j] = (dp[k][i][j] && dp[len - k][i + k][j + k]) ||
                            (dp[k][i][j + len - k] && dp[len - k][i + k][j]);
            if (dp[len][i][j]) {
              break;
            }
          }
          //   printf("dp[%d][%d][%d] = %d\n", len, i, j, dp[len][i][j]);
        }
      }
    }
    return dp[s1.size()][0][0];
  }
};
// @lc code=end
