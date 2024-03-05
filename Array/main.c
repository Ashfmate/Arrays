#include "main.h"
#include <stdio.h>
// Filter Function

Array* createNewArray(unsigned long long capacity) {
  Array* result = (Array*)malloc(sizeof(Array));
  if (result == NULL) {
    return NULL;
  }
  result->m_data = (int*)malloc(sizeof(int) * capacity);
  if (result->m_data == NULL) {
    return NULL;
  }
  result->size = 0;
  result->capacity = capacity;
  return result;
}

Array* filter(Array const * const arr, const bool(* const func)(const int)) {
  Array* new_arr = createNewArray(arr->size);
  for (int i = 0; i < arr->size; ++i) {
    if (func(arr->m_data[i])) {
      new_arr->m_data[new_arr->size++] = arr->m_data[i];
    }
  }
  return new_arr;
}

// Filter Function

// ForEach Function

void forEach(Array const * const arr, void(*func)(const int)) {
  for (int i = 0; i < arr->size; ++i) {
    func(arr->m_data[i]);
  }
}

// ForEach Function

// Transform Function

void transform(Array * const arr, void(*func)(int*const)) {
  for (int i = 0; i < arr->size; ++i) {
    func(&(arr->m_data[i]));
  }
}

// Transform Function

// Fill Functions
void fill(Array *const arr, int value) {
  for (int i = 0; i < arr->size; ++i) {
    arr->m_data[i] = value;
  }
}

void fill_cap(Array *const arr, int value) {
  while (arr->size <= arr->capacity) {
    arr->m_data[arr->size++] = value;
  }
}
// Fill Functions
