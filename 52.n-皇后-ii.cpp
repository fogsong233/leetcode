/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N 皇后 II
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int totalNQueens(int n) {
    using StatusVec = vector<int>;
    StatusVec rows = StatusVec(n + 1);
    StatusVec cols(n + 1);
    StatusVec ses(2 * n);
    StatusVec nes(2 * n);
    int res = 0;
    int nowX = 1;
    int nowY = 1;
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
    auto dfs = [&](auto &&self, int total) -> void {
      if (nowY == n + 1) {
        if (total == n) {
          res++;
        }
        return;
      }
      bool state =
          cols[nowX] | rows[nowY] | ses[nowX - nowY + n] | nes[nowX + nowY - 1];
      if (state) {
        nxt();
        self(self, total);
        pre();
      } else {
        cols[nowX]++;
        rows[nowY]++;
        ses[nowX - nowY + n]++;
        nes[nowX + nowY - 1]++;
        nxt();
        self(self, total + 1);
        pre();
        cols[nowX]--;
        rows[nowY]--;
        ses[nowX - nowY + n]--;
        nes[nowX + nowY - 1]--;
        nxt();
        self(self, total);
        pre();
      }
    };
    dfs(dfs, 0);
    return res;
  }
};
// @lc code=end
