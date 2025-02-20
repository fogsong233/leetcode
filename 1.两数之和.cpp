/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> res(2);
    unordered_map<int, int> set{};
    for (int i = 0; i < nums.size(); ++i) {
      int num = nums[i];
      if (set.find(target - num) == set.end()) {
        set[num] = i;
      } else {
        res = {set[target - num], i};
      }
    }
    return res;
  }
};
// @lc code=end
