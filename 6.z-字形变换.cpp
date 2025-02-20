/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

using namespace std;
#include <cstdlib>
#include <memory>
#include <string_view>
// @lc code=start
class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1)
      return s;
    int eqClassNum = 2 * numRows - 2;
    auto *res = (char *)malloc((s.size() + 1));
    res[s.size()] = '\0';
    int k = 0;
    // 第一层
    for (size_t i = 0; i < s.size(); i += eqClassNum) {
      res[k++] = s[i];
    }
    // 中间两个
    for (int l = 2; l < numRows; l++) {
      int i = (l - 1);
      int j = eqClassNum - l + 1;
      while (true) {
        if (i < s.size()) {
          res[k++] = s[i];
        }
        if (j < s.size()) {
          res[k++] = s[j];
        } else {
          break;
        }
        i += eqClassNum;
        j += eqClassNum;
      }
    }
    // 最后一层
    for (size_t i = numRows - 1; i < s.size(); i += eqClassNum) {
      res[k++] = s[i];
    }
    return res;
  }
};
// @lc code=end
