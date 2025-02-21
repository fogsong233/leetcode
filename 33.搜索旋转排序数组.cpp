/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int search(vector<int> &nums, int target) {
    int i = 0;
    int j = nums.size() - 1;
    // find division
    int div = 0;
    int end = nums.back();
    while (j - i > 1) {
      if (nums[(i + j) / 2] > end) {
        i = (i + j) / 2;
      } else {
        j = (i + j) / 2;
      }
    }
    if (nums[i] <= nums[j]) {
      i = 0;
      j = nums.size() - 1;
    } else if (target <= end) {
      i = j;
      j = nums.size() - 1;
    } else {
      j = i;
      i = 0;
    }
    while (j > i) {
      int center = (i + j) / 2;
      if (nums[center] < target) {
        i = center + 1;
      } else {
        j = center;
      }
    }
    return nums[j] == target ? j : -1;
  }
};
// @lc code=end
