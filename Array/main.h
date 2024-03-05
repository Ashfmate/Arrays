#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  int* m_data;
  unsigned long long size;
  unsigned long long capacity;
} Array;

// Function Declarations
Array* createNewArray(unsigned long long capacity);
Array* filter(Array const*const arr, const bool(* const func)(const int));
void forEach(Array const*const arr, void(* const func)(const int));
void transform(Array *const arr, void(* const func)(int*const));
void fill(Array *const arr, int value);
void fill_cap(Array *const arr, int value);
// Function Declarations
