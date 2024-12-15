// Example 03 - Struct data type demonstration
#include <assert.h>
#include <limits.h>
#include <math.h>

struct data {
  int a;
  char b;
  double c;
};

int main(void) {
  struct data x;

  x.a = INT_MAX;
  x.b = 'a';
  x.c = M_PI;

  assert(x.a == INT_MAX);
  assert(x.b == 'a');
  assert(x.c == M_PI);
  return 0;
}
