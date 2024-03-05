#include "Array/main.h"
#include <time.h>
#include <stdio.h>

void giveRandom(int *const elem) {
  *elem = rand();
}

void print(int elem) {
  printf("%d ", elem);
}

int main() {
  srand(time(0));
  Array *arr = createNewArray(10);
  fill_cap(arr, 0);
  transform(arr, giveRandom);
  forEach(arr, print);
}
