#include "Array/main.h"
#include <stdlib.h>
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
  if (arr == NULL) {
    fprintf(stderr, "Could not create an array");
    exit(EXIT_FAILURE);
  }
  fill_cap(arr, 0);
  transform(arr, giveRandom);
  forEach(arr, print);
  deleteArray(&arr);
  if (arr == NULL) {
    printf("Successfully deleted array");
  }
}
