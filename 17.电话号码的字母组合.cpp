/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
#include <deque>
#include <iterator>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  unordered_map<char, const char *> strMap = {
      {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
      {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
  };
  vector<string> letterCombinations(string digits) {
    if (digits == "")
      return vector<string>();
    deque<string> deq{""};
    int times = 0;
    while (times < digits.size()) {
      char c = digits[times];
      int size = deq.size();
      while (size--) {
        auto preStr = deq.front();
        deq.pop_front();
        int i = 0;
        while (char letter = strMap[c][i++]) {
          deq.push_back(preStr + letter);
        }
      }
      times++;
    }
    return vector<string>(make_move_iterator(deq.begin()),
                          make_move_iterator(deq.end()));
  }
};
// @lc code=end
