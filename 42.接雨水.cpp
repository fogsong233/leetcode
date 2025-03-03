/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

#include <cstdio>
#include <utility>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int trap(vector<int> &heights) {
    if (heights.size() <= 2)
      return 0;
    int leftMax = 0;
    int rightMax = heights.size() - 1;
    int left = 0;
    int right = heights.size() - 1;
    int result = 0;
    while (left < right) {
      if (heights[leftMax] < heights[rightMax]) {
        if (heights[left] <= heights[leftMax]) {
          result += heights[leftMax] - heights[left];
          left++;
        } else {
          leftMax = left;
        }
      } else {
        if (heights[right] <= heights[rightMax]) {
          result += heights[rightMax] - heights[right];
          right--;
        } else {
          rightMax = right;
        }
      }
    }
    return result;
  }
};
// @lc code=end
