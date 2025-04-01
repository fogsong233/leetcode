/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */
#include <cstddef>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int numIslands(vector<vector<char>> &grid) {
    // 遍历完整一遍,每次遇到未经过遍历的岛深搜遍历完这个岛
    vector<vector<bool>> reached(grid.size(),
                                 vector<bool>(grid.front().size()));

    auto check = [&](auto &&f, int i, int j) {
      if (i >= grid.size() || i < 0 || j < 0 || j >= grid.front().size()) {
        return;
      }
      if (grid[i][j] == '0' || reached[i][j]) {
        return;
      }
      reached[i][j] = true;
      f(f, i + 1, j);
      f(f, i - 1, j);
      f(f, i, j + 1);
      f(f, i, j - 1);
    };
    int num = 0;
    for (size_t i = 0; i < grid.size(); i++) {
      for (size_t j = 0; j < grid.front().size(); j++) {
        if (reached[i][j] || grid[i][j] == '0') {
          continue;
        }
        check(check, i, j);
        num++;
      }
    }
    return num;
  }
};
// @lc code=end
