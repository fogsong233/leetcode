/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */
#include <numeric>
#include <vector>
using namespace std;
// @lc code=start
class UF {
public:
  int sz;
  vector<int> ids;

  UF(int sz) : sz(sz) {
    ids = vector<int>(sz + 1);
    iota(ids.begin(), ids.end(), 0);
  }
  int find(int q) {
    vector<int> middles{};
    while (ids[q] != q) {
      middles.push_back(q);
      q = ids[q];
    }
    for (const auto &v : middles) {
      ids[v] = q;
    }
    return q;
  }
};
class Solution {
public:
  vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    UF uf(edges.size());
    for (const auto &edge : edges) {
      int id1 = uf.find(edge.front());
      int id2 = uf.find(edge[1]);
      if (id1 == id2) {
        return edge;
      }
      uf.ids[id1] = id2;
    }
    return edges.back();
  }
};
// @lc code=end
