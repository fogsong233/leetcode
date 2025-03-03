/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

#include <algorithm>
#include <climits>
#include <cstdint>
#include <cstdlib>
#include <ranges>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    auto size = nums.size();
    for (int i = 0; i < size;) {
      auto num = nums[i];
      if (num <= size && num > 0) {
        if (nums[num - 1] != num) {
          swap(nums[num - 1], nums[i]);
          continue;
        }
      }
      i++;
    }
    for (int i = 0; i < size; i++) {
      if (nums[i] != i + 1) {
        return i + 1;
      }
    }
    return size + 1;
  }
};
// @lc code=end
