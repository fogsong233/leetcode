/*
 * @lc app=leetcode.cn id=472 lang=cpp
 *
 * [472] 连接词
 */
#include <string>
#include <string_view>
#include <vector>
using namespace std;
// @lc code=start
struct Piece {
  string_view nowStr;
  int fromIndex;
};

class Solution {
public:
  vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
    vector<Piece> queue{};
  }
};
// @lc code=end
