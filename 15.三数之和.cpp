/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <iterator>
#include <ranges>
#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> finalRes{};
    ranges::sort(nums);
    int befValue = nums[0] - 1;
    for (int i = 0; i < nums.size() - 2; i++) {
      if (befValue == nums[i])
        continue;
      int remain = -nums[i];
      auto res = findTwoValueSumEqualTo(remain, i + 1, nums);
      res = res | views::transform([&](auto &vec) {
              vec.push_back(-remain);
              return vec;
            }) |
            ranges::to<vector<vector<int>>>();
      ranges::move(res, back_inserter(finalRes));
      befValue = nums[i];
    }
    return finalRes;
  }

  vector<vector<int>> findTwoValueSumEqualTo(int sum, int startIndex,
                                             vector<int> &nums) {
    vector<vector<int>> res{};
    int i = startIndex;
    int j = nums.size() - 1;
    while (j > i) {
      const int thisSum = nums[i] + nums[j];
      if (thisSum == sum) {
        res.push_back(vector<int>{nums[i], nums[j]});
        int nowNum = nums[i];
        while (i < j && nums[++i] == nowNum) {
        }
        continue;
      }
      if (thisSum > sum) {
        j--;
      } else {
        i++;
      }
    }
    return res;
  }
};
// @lc code=end
