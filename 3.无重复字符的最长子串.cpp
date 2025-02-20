/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

#include <algorithm>
#include <iostream>
using namespace std;
#include <string>
// @lc code=start
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int m = 0;
    int i;
    int j;
    if (s.size() <= 1)
      return s.size();
    for (i = 0, j = 0; j < s.size(); ++j) {
      for (int p = i; p < j; ++p) {
        // cout << i << j << endl;
        if (s[p] == s[j]) {
          m = max(m, j - i);
          i = p + 1;
          break;
        }
      }
    }
    // cout << i << j;
    m = max(m, j - i);
    return m;
  }
};
// @lc code=end
