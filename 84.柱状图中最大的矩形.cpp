/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

#include <stack>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    // only to know that in this element, use this height, the max area
    // using incresing stack
    int maxArea = 0;
    auto getEle = [&](int index) -> int {
      if (index == 0)
        return 0;
      if (index == heights.size() + 1)
        return 0;
      return heights[index - 1];
    };
    int size = heights.size() + 2;
    stack<int> s{};
    s.push(0);
    for (int i = 1; i < size; i++) {
      if (getEle(s.top()) <= getEle(i)) {
        s.push(i);
        continue;
      }
      while (!s.empty() && getEle(s.top()) > getEle(i)) {
        auto height = getEle(s.top());
        s.pop();
        maxArea = max(maxArea, (i - s.top() - 1) * height);
      }
      s.push(i);
    }
    return maxArea;
  }
};
// @lc code=end
