/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

#include <algorithm>
#include <cstdio>
#include <deque>
#include <iostream>
#include <ranges>
#include <string>
#include <utility>
#include <vector>
using namespace std;
// @lc code=start
class Solution {

  struct Seq {
    string values;
    int sum = 0;
    int remain = 3;
  };

public:
  static vector<string> generateParenthesis(int n) {
    if (n == 1) {
      return {"()"};
    }
    vector<string> res{};
    deque<Seq> seqs{};
    seqs.push_back({{'('}, 1, n - 1});

    while (!seqs.empty()) {

      auto top = std::move(seqs.front());
      seqs.pop_front();

      if (top.remain == 0) {
        string r{};
        while (top.sum > 0) {
          top.values.push_back(')');
          top.sum--;
        }
        res.push_back(std::move(top.values));
      } else {
        if (top.sum > 0) {
          Seq newSeq = top;
          newSeq.values.push_back(')');
          newSeq.sum--;
          seqs.push_back(std::move(newSeq));
        }
        top.values.push_back('(');
        top.sum++;
        top.remain--;
        seqs.push_back(std::move(top));
      }
    }
    return res;
  }
};

// @lc code=end
