// Example 05 - Packed (and aligned) struct demonstration
#include <assert.h>
#include <stdbool.h>

struct __attribute__((packed)) data {
  int a;
  char b;
  bool *c;
};

int main(void) {
  assert(sizeof(struct data) == 16);
  return 0;
}
