/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
<<<<<<< HEAD
  int maxArea(vector<int> &height) {}
=======
  int maxArea(vector<int> &heights) {
    int i = 0;
    int j = heights.size() - 1;
    int maxCapcity = 0;
    while (j > i) {
      maxCapcity = max(maxCapcity, (j - i) * min(heights[i], heights[j]));
      if (heights[i] > heights[j]) {
        j--;
      } else {
        i++;
      }
    }
    return maxCapcity;
  }
>>>>>>> 353bf9d (chromebook init)
};
// @lc code=end
