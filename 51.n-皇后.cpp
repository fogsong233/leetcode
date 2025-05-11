/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */
#include <cstdio>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
struct Queens {
  vector<string> data;
  int qs = 0;
  explicit Queens(int n) : data(vector<string>(n, string(n, '.'))) {}
  void setQueen(int x, int y) {
    data[x - 1][y - 1] = 'Q';
    qs++;
  }
  void recoverQueen(int x, int y) {
    data[x - 1][y - 1] = '.';
    qs--;
  }
};

class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    using StatusVec = vector<int>;
    StatusVec rows = StatusVec(n + 1);
    StatusVec cols(n + 1);
    StatusVec ses(2 * n);
    StatusVec nes(2 * n);
    vector<vector<string>> res{};
    int nowX = 1;
    int nowY = 1;
    Queens flags(n);
    auto nxt = [&]() {
      if (nowX == n) {
        nowX = 1;
        nowY++;
      } else {
        nowX++;
      }
    };
    auto pre = [&]() {
      if (nowX == 1) {
        nowX = n;
        nowY--;
      } else {
        nowX--;
      }
    };
    auto dfs = [&](auto &&self) -> void {
      if (nowY == n + 1) {
        if (flags.qs == n) {
          res.push_back(flags.data);
        }
        return;
      }
      bool state =
          cols[nowX] | rows[nowY] | ses[nowX - nowY + n] | nes[nowX + nowY - 1];
      if (state) {
        nxt();
        self(self);
        pre();
      } else {
        flags.setQueen(nowX, nowY);
        cols[nowX]++;
        rows[nowY]++;
        ses[nowX - nowY + n]++;
        nes[nowX + nowY - 1]++;
        nxt();
        self(self);
        pre();
        cols[nowX]--;
        rows[nowY]--;
        ses[nowX - nowY + n]--;
        nes[nowX + nowY - 1]--;
        flags.recoverQueen(nowX, nowY);
        nxt();
        self(self);
        pre();
      }
    };
    dfs(dfs);
    return res;
  }
};
// @lc code=end
