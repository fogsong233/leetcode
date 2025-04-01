#include <set>
#include <vector>
using namespace std;

class Cover {
public:
  int varNum;
  set<int> coverMinItems{};
  int nowMinItem;
  Cover(int varNum, int nowMinItem) : nowMinItem(nowMinItem), varNum(varNum) {}
};