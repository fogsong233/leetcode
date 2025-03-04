/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

#include <climits>
#include <cstdio>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  string minWindow(string s, string t) {
    unordered_map<char, int> has{};
    unordered_map<char, int> standard{};
    vector<int> orderCharIndexes{};
    int tSize = t.size();
    for (auto c : t) {
      standard[c]++;
    }
    int minStart = 0;
    int minLength = INT_MAX;
    for (size_t i = 0; i <= s.length(); i++) {
      if (standard[s[i]] > 0) {
        has[s[i]]++;
        orderCharIndexes.push_back(i);
        while (has[s[orderCharIndexes.front()]] >
               standard[s[orderCharIndexes.front()]]) {
          // 撤退
          has[s[orderCharIndexes.front()]]--;
          orderCharIndexes.erase(orderCharIndexes.begin());
        }
      }
      if (orderCharIndexes.size() >= tSize) {
        bool isOk = true;
        for (const auto &pair : standard) {
          if (has[pair.first] < pair.second) {
            isOk = false;
            break;
          }
        }
        if (!isOk) {
          continue;
        }
        if (orderCharIndexes.back() - orderCharIndexes.front() + 1 <
            minLength) {
          minLength = orderCharIndexes.back() - orderCharIndexes.front() + 1;
          minStart = orderCharIndexes.front();
        }
      }
    }
    if (minLength < INT_MAX) {
      return string{s.begin() + minStart, s.begin() + minStart + minLength};
    }
    return "";
  }
};
// @lc code=end