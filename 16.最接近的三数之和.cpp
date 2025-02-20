/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16]
 */
#include <algorithm>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <iterator>
#include <ranges>
#include <vector>

// @lc code=start
using namespace std;
class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    vector<vector<int>> finalRes{};
    ranges::sort(nums);
    int res;
    int closestSum = INT_MAX;
    for (int k = 0; k < nums.size() - 2; k++) {
      int i = k + 1;
      int j = nums.size() - 1;
      while (j > i) {
        const int thisSum = nums[i] + nums[j] + nums[k];
        if (thisSum == target) {
          return target;
        }
        if (abs(target - thisSum) < closestSum) {
          res = thisSum;
          closestSum = abs(target - thisSum);
        }
        if (thisSum > target) {
          j--;
        } else {
          i++;
        }
      }
    }
    return res;
  }
};
// @lc code=end
