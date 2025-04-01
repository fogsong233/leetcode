/*
 * @lc app=leetcode.cn id=1329 lang=cpp
 *
 * [1329] 将矩阵按对角线排序
 */
#include <array>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<vector<int>> diagonalSort(vector<vector<int>> &mat) {
    int m = mat.size();
    int n = mat.front().size();
    array<int, 101> buckets{0};
    for (int _column = m - 1, _row = 0; _row < n - 1;
         (_column > 0) ? _column-- : _row++) {
      int column = _column;
      int row = _row;
      buckets = {};
      while (column < m && row < n) {
        buckets[mat[column++][row++]]++;
      }
      column = _column;
      row = _row;
      for (int j = 1; j <= 100; j++) {
        auto value = buckets[j];
        for (int k = 0; k < value; k++) {
          mat[column++][row++] = j;
        }
      }
    }
    return mat;
  }
};
// @lc code=end
