/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

#include <cstdio>
#include <tuple>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int maximalRectangle(vector<vector<char>> &matrix) {
    int width = matrix[0].size();
    int height = matrix.size();
    vector<int> heights(width + 2, 0);
    int maxRect = 0;
    for (int i = 0; i < height; i++) {
      vector<int> s{0};
      for (int j = 1; j < width + 2; j++) {
        if (j > 0 && j <= width) {
          heights[j] = matrix[i][j - 1] == '1' ? heights[j] + 1 : 0;
        }
        while (heights[s.back()] > heights[j]) {
          auto index = s.back();
          s.pop_back();
          // printf("%d %d %d\n", s.back(), j, heights[index]);
          maxRect = max(maxRect, (j - s.back() - 1) * heights[index]);
        }
        s.push_back(j);
      }
    }
    return maxRect;
  }
};
// @lc code=end
