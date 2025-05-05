/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */
#include <string>
#include <string_view>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  vector<vector<int>> cache;

public:
  int numDistinct(string s, string t) {
    cache = vector<vector<int>>(s.size() + 1, vector<int>(t.size() + 1, -1));
    return numDistinct(string_view(s), string_view(t));
  }
  int numDistinct(string_view s, string_view t) {
    if (cache[s.size()][t.size()] != -1) {
      return cache[s.size()][t.size()];
    }
    int res = 0;
    int a = s.size();
    if (t.size() == 0) {
      return 1;
    }
    if (s.size() == 0) {
      return 0;
    }
    auto subS = s.substr(1);
    auto subT = t.substr(1);
    res += numDistinct(subS, t); // 不选
    if (t[0] == s[0]) {
      res += numDistinct(subS, subT);
    }
    cache[s.size()][t.size()] = res;
    return res;
  }
};
// @lc code=end
