/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */
#include <cstddef>
#include <map>
#include <vector>
using namespace std;
class Node {
public:
  int val;
  vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};
// @lc code=start
/*
// Definition for a Node.

*/

class Solution {
private:
  map<int, Node *> newNodes;
  bool isChecked(int val) { return newNodes.find(val) != newNodes.end(); }

public:
  Node *cloneGraph(Node *node) {
    if (node == nullptr) {
      return nullptr;
    }
    // 广度优先搜索
    auto *startNode = new Node(node->val);
    newNodes[startNode->val] = startNode;
    _cloneGraph(startNode, node);
    return startNode;
  }

  // 把这个节点的邻居clone了, 这是新node
  void _cloneGraph(Node *node, Node *befNode) {
    for (const auto &neighbor : befNode->neighbors) {
      if (isChecked(neighbor->val)) {
        node->neighbors.push_back(newNodes[neighbor->val]);
      } else {
        auto *newNeighbor = new Node(neighbor->val);
        newNodes[neighbor->val] = newNeighbor;
        node->neighbors.push_back(newNeighbor);
        _cloneGraph(newNeighbor, neighbor);
      }
    }
  }
};
// @lc code=end
