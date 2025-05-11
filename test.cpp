#include <cstdio>
#include <print>
class A {
public:
  int a;
  int b;
};
int main(int argc, const char **argv) {
  A a;
  std::printf("%d%d", a.a, a.b);
  return 0;
}