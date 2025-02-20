/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <algorithm>
#include <cstddef>
#include <iterator>
#include <ranges>
#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> finalRes{};
    ranges::sort(nums);
    ranges::unique(nums);
    for (int i = 0; i < nums.size() - 2; i++) {
      int remain = -nums[i];
      auto res = findTwoValueSumEqualTo(remain, i + 1, nums);
      res | views::transform([&](auto &vec) {
        vec.push_back(-remain);
        return vec;
      });
      ranges::move(res, back_inserter(finalRes));
    }
    return finalRes;
  }

  vector<vector<int>> findTwoValueSumEqualTo(int sum, int startIndex,
                                             vector<int> &nums) {
    vector<vector<int>> res{};
    while (startIndex < nums.size() - 1) {
      int remain = sum - nums[startIndex];
      int i = startIndex + 1;
      int j = nums.size() - 1;
      while (j - i >= 0) {
        int center = (i + j) / 2;
        int value = nums[center];
        if (value == remain) {
          res.push_back(vector<int>{sum - remain, remain});
          break;
        }
        if (value < remain) {
          i = center + 1;
        } else {
          j = center - 1;
        }
      }
      startIndex++;
    }
    for (const auto &vec : res)
      printf("found [%d, %d] \n", vec[0], vec[1]);
    return res;
  }
};
// @lc code=end
