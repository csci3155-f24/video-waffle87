// Example 02 - Inline assembly demonstration
#include <assert.h>

char *asm_fn(void) {
  asm("mov $50, %rax\n\t"
      "mov %rbp, %rsp\n\t"
      "pop %rbp\n\t"
      "ret");
}

int main(void) {
  assert((long)asm_fn() == 50);
  return 0;
}
