/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */
#include <cmath>
#include <cstdio>
#include <functional>
#include <map>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
  map<int, char, greater<int>> romanMap{{1000, 'M'}, {500, 'D'}, {100, 'C'},
                                        {50, 'L'},   {10, 'X'},  {5, 'V'},
                                        {1, 'I'}};

  string intToRoman(int num) {
    char res[50]{};
    int i = 0;
    while (num > 0) {
      int num_length = bool(num / 1000)
                           ? 4
                           : (bool(num / 100) ? 3 : (bool(num / 10) ? 2 : 1));
      int sameDigitStarWithOne = int(pow(10, num_length - 1));
      //   printf("now res is %s, num remain %d, one is%d\n", res.c_str(), num,
      //          sameDigitStarWithOne);

      int firstDigit = num / sameDigitStarWithOne;
      if (firstDigit == 4) {
        res[i++] = romanMap[sameDigitStarWithOne];
        res[i++] = romanMap[5 * sameDigitStarWithOne];
        num -= 4 * sameDigitStarWithOne;
      } else if (firstDigit == 9) {
        res[i++] = romanMap[sameDigitStarWithOne];
        res[i++] = romanMap[sameDigitStarWithOne * 10];
        num -= 9 * sameDigitStarWithOne;
      } else {
        for (const auto &item : romanMap) {
          if (num >= item.first) {
            res[i++] = item.second;
            num -= item.first;
            break;
          }
        }
      }
    }
    return res;
  }
};
// @lc code=end
