/*
 * @lc app=leetcode.cn id=1328 lang=cpp
 *
 * [1328] 破坏回文串
 */

#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
  string breakPalindrome(string palindrome) {
    if (palindrome.size() == 1) {
      return "";
    }
    for (int k = 0; k < palindrome.size(); k++) {
      if (k == palindrome.size() - 1 && palindrome.back() == 'a') {
        palindrome.back() = 'b';
        return palindrome;
      }
      if (k == palindrome.size() - 1 - k || palindrome[k] == 'a') {
        continue;
      }
      palindrome[k] = 'a';
      return palindrome;
    }
    return "";
  }
};
// @lc code=end
