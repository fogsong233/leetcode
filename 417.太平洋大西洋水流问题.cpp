/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {

  vector<vector<int>> *_heights;
  void checkFrom(int compare, int i, int j, vector<vector<bool>> &markVec) {
    if (i < 0 || j < 0 || j >= _heights->front().size() ||
        i >= _heights->size()) {
      return;
    }
    if (markVec[i][j]) {
      return;
    }
    if (compare <= (*_heights)[i][j]) {
      markVec[i][j] = true;
      checkFrom((*_heights)[i][j], i - 1, j, markVec);
      checkFrom((*_heights)[i][j], i + 1, j, markVec);
      checkFrom((*_heights)[i][j], i, j + 1, markVec);
      checkFrom((*_heights)[i][j], i, j - 1, markVec);
    }
  }

public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    this->_heights = &heights;
    vector<vector<bool>> pacific(heights.size(),
                                 vector<bool>(heights.front().size()));
    vector<vector<bool>> atlantic(heights.size(),
                                  vector<bool>(heights.front().size()));
    for (int i = 0; i < heights.size(); i++) {
      checkFrom(-1, i, 0, pacific);
    }
    for (int i = 0; i < heights.front().size(); i++) {
      checkFrom(-1, 0, i, pacific);
    }
    for (int i = 0; i < heights.size(); i++) {
      checkFrom(-1, i, heights.front().size() - 1, atlantic);
    }
    for (int i = 0; i < heights.front().size(); i++) {
      checkFrom(-1, heights.size() - 1, i, atlantic);
    }
    vector<vector<int>> res;
    for (int i = 0; i < heights.size(); i++) {
      for (int j = 0; j < heights.front().size(); j++) {
        if (atlantic[i][j] && pacific[i][j]) {
          res.push_back(vector{i, j});
        }
      }
    }
    return res;
  }
};
// @lc code=end
