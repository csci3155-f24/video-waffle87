// Example 04 - Multithreaded program demonstration
#include <assert.h>
#include <pthread.h>
#include <stdlib.h>

#define MSG "hello from thread!"

void *thread_main(void *a) {
  int arg = *((int *)a);
  free(a);
  assert(arg == 123);
  return NULL;
}

int main(void) {
  pthread_t thread;
  int *arg = (int *)malloc(sizeof(int));
  *arg = 123;
  pthread_create(&thread, NULL, thread_main, arg);
  pthread_join(thread, NULL);
  return 0;
}
