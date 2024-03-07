#include "main.h"
#include <stdio.h>
#include <assert.h>
// Creating and Deletion Functions

Array* createNewArray(unsigned long long capacity) {
  printf("\r");
  Array* result = (Array*)malloc(sizeof(Array));
  if (result == NULL) {
    return NULL;
  }
  result->m_data = (int*)malloc(sizeof(int) * capacity);
  if (result->m_data == NULL) {
    free(result);
    return NULL;
  }
  result->size = 0;
  result->capacity = capacity;
  return result;
}

bool deleteArray(Array** arr) {
  if (*arr == NULL) {
    return false;
  }
  if ((*arr)->m_data == NULL) {
    free(arr);
    return false;
  }
  free((*arr)->m_data);
  free(*arr);
  *arr = NULL;
  return true;
}

// Creating and Deletion Functions
//////////////////////////////////////////////////////////////////////////////////////
// Filter Function

Array* filter(Array const * const arr, pred_t pred) {
  Array* new_arr = createNewArray(arr->size);
  for (int i = 0; i < arr->size; ++i) {
    if (pred(arr->m_data[i])) {
      new_arr->m_data[new_arr->size++] = arr->m_data[i];
    }
  }
  return new_arr;
}

// Filter Function
//////////////////////////////////////////////////////////////////////////////////////
// ForEach Function

void forEach(Array const * const arr, void(*func)(const int)) {
  for (int i = 0; i < arr->size; ++i) {
    func(arr->m_data[i]);
  }
}

// ForEach Function
//////////////////////////////////////////////////////////////////////////////////////
// Transform Function

void transform(Array * const arr, void(*func)(int*const)) {
  for (int i = 0; i < arr->size; ++i) {
    func(&(arr->m_data[i]));
  }
}

// Transform Function
//////////////////////////////////////////////////////////////////////////////////////
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
//////////////////////////////////////////////////////////////////////////////////////
// Find Functions

int itemAt(Array const * const arr, size_t index) {
  return *itemAtRef(arr, index);
}

int* itemAtRef(Array const * const arr, size_t index) {
  assert(arr->size > index);
  return &(arr->m_data[index]);
}

Array* find(Array const * const arr, int value) {
  Array* res = createNewArray(arr->size);
  for (int i = 0; i < arr->size; i++) {
    if (arr->m_data[i] == value) {
      res->m_data[res->size++] = i;
    }
  }
  return res;
}

Array* findFunc(Array const * const arr, pred_t pred) {
  Array* res = createNewArray(arr->size);
  for (int i = 0; i < arr->size; i++) {
    if (pred(arr->m_data[i])) {
      res->m_data[res->size++] = i;
    }
  }
  return res;
}

int* findFirst(Array const * const arr, int value) {
  for (int i = 0; i < arr->size; i++) {
    if (arr->m_data[i] == value) {
      return &(arr->m_data[i]);
    }
  }
  return NULL;
}

int* findLast(Array const * const arr, int value) {
  for (int i = arr->size - 1; i >= 0; i++) {
    if (arr->m_data[i] == value) {
      return &(arr->m_data[i]);
    }
  }
  return NULL;
}

int* findFirstFunc(Array const * const arr, pred_t pred) {
  for (int i = 0; i < arr->size; i++) {
    if (pred(arr->m_data[i])) {
      return &(arr->m_data[i]);
    }
  }
  return NULL;
}
int* findLastFunc(Array const * const arr, pred_t pred) {
  for (int i = arr->size - 1; i >= 0; i++) {
    if (pred(arr->m_data[i])) {
      return &(arr->m_data[i]);
    }
  }
  return NULL;
}

// Find Functions
//////////////////////////////////////////////////////////////////////////////////////
// Size Manipulation Functions

// Size Manipulation Functions

