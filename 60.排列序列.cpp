/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 排列序列
 */

#include <numeric>
#include <ranges>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  vector<bool> used;
  vector<int> rang;

public:
  string getPermutation(int n, int k) {
    used = vector<bool>(n, false);
    rang = vector<int>(n);
    iota(rang.begin(), rang.end(), 0);
    return findKthPermOfN(k, n, "");
  }

  int fact(int n) { return n == 1 ? 1 : n * fact(n - 1); }

  string findKthPermOfN(int k, int n, string prefix) {
    int kth;
    if (n == 1) {
      kth = 1;
    } else {
      kth = fact(n - 1);
    }
    prefix += ('0' +
               *(ranges::find_if(rang,
                                 [&](int v) {
                                   if (used[v]) {
                                     return false;
                                   }
                                   if (k <= kth) {
                                     used[v] = true;
                                     return true;
                                   }
                                   k -= kth;
                                   return false;
                                 })) +
               1);
    if (prefix.size() == used.size()) {
      return prefix;
    }
    char a = (char)1;
    return findKthPermOfN(k, n - 1, prefix);
  }
};
// @lc code=end
