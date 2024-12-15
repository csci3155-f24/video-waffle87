// Example 02 - Inline assembly demonstration
#include <assert.h>

char *asm_fn1(void) {
  asm("mov $50, %rax\n\t"
      "mov %rbp, %rsp\n\t"
      "pop %rbp\n\t"
      "ret");
}

char *asm_fn2(void) {
  asm inline volatile("mov $55, %rax\n\t"
                      "mov %rbp, %rsp\n\t"
                      "pop %rbp\n\t"
                      "ret");
}

int main(void) {
  assert((long)asm_fn1() == 50);
  assert((long)asm_fn2() == 55);
  return 0;
}
