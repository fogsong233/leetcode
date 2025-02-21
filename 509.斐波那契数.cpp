/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */
// 使用快速幂
using namespace std;
// @lc code=start
using ll = long long;
struct Matrix {
  ll a11;
  ll a12;
  ll a21;
  ll a22;
  Matrix operator*(const Matrix &other) const {
    return Matrix{.a11 = this->a11 * other.a11 + this->a12 * other.a21,
                  .a12 = this->a11 * other.a12 + this->a12 * other.a22,
                  .a21 = this->a21 * other.a11 + this->a22 * other.a21,
                  .a22 = this->a21 * other.a12 + this->a22 * other.a22};
  }
};
const Matrix baseMatrix = {.a11 = 1, .a12 = 1, .a21 = 1, .a22 = 0};
class Solution {
public:
  Matrix powOf(int times) {
    if (times == 1)
      return baseMatrix;
    return powOf(times / 2) * powOf(times - (times / 2));
  }

  int fib(int n) {
    if (n == 0)
      return 0;
    if (n == 1)
      return 1;
    const auto mat = powOf(n - 1);
    return mat.a11;
  }
};
// @lc code=end
