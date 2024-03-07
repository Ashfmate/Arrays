#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  int* m_data;
  unsigned long long size;
  unsigned long long capacity;
} Array;

typedef const bool(* const pred_t)(const int);

// Function Declarations
// Creation and Deletion Functions
Array* createNewArray(unsigned long long capacity);
bool deleteArray(Array** arr);
// Creation and Deletion Functions
// Recreational Functions
void transform(Array *const arr, void(* const func)(int*const));
void fill(Array *const arr, int value);
void fill_cap(Array *const arr, int value);
// Recreational Functions
// For Each Functions
void forEach(Array const*const arr, void(* const func)(const int));
// For Each Functions
// Searching Functions
Array* filter(Array const*const arr, pred_t pred);
Array* find(Array const * const arr, int value);
Array* findFunc(Array const * const arr, pred_t pred);
int* findFirst(Array const * const arr, int value);
int* findLast(Array const * const arr, int value);
int* findFirstFunc(Array const * const arr, pred_t pred);
int* findLastFunc(Array const * const arr, pred_t pred);
size_t count(Array const * const arr, int value);
size_t countFunc(Array const * const arr, pred_t pred);
// Searching Functions
// Sorting Functions
Array* sort(Array const * const arr);
Array* sortFunc(Array const * const arr, const bool( * const pred) (const int, const int));
Array* reverse(Array const * const arr);
// Sorting Functions
// Reduction Functions
int reduce(Array const * const arr, int init);
int reduceFunc(Array const * const arr, int init, void(* const func)(int* const, const int ));
int min(Array const * const arr);
int minFunc(Array const * const arr); 
int max(Array const * const arr);
int maxFunc(Array const * const arr);
// Reduction Functions
// Concatenation Functions
Array* concat(Array const * const arr, Array const * const other);
Array* merge(Array const * const arr, Array const * const other, const bool(*const pred)(const int, const int));
// Concatenation Functions
// Grouping Functions
Array* partition(Array const * const arr, pred_t pred);
Array* groupBy(Array const * const arr, const size_t( * const func)(const int));
// Grouping Functions
// Equality Functions
bool isEqual(Array const * const arr, Array const * const other);
bool isMore(Array const * const arr, Array const * const other);
bool isMoreEqual(Array const * const arr, Array const * const other);
bool isLess(Array const * const arr, Array const * const other);
bool isLessEqual(Array const * const arr, Array const * const other);
bool allOf(Array const * const arr, pred_t pred);
bool anyOf(Array const * const arr, pred_t pred);
bool noneOf(Array const * const arr, pred_t pred);
// Equality Functions
// Access Functions
int itemAt(Array const * const arr, size_t index);
int* itemAtRef(Array const * const arr, size_t index);
int front(Array const * const arr);
int* frontRef(Array const * const arr);
int back(Array const * const arr);
int* backRef(Array const * const arr);
// Access Functions
// Size Manipulation Functions
bool pushBack(Array * const arr);
bool pushRangeBack(Array * const arr, Array const * const other);
bool pushFront(Array * const arr);
bool pushRangeFront(Array * const arr, Array const * const other);
bool pushRangeFrom(Array * const arr, Array const * const other, size_t from);
bool popBack(Array * const arr);
bool popFront(Array * const arr);
bool popRange(Array * const arr, size_t from, size_t to);
bool popRangeN(Array * const arr, size_t from, size_t num);
bool popToEnd(Array * const arr, size_t from);
// Size Manipulation Functions
// Element Manipulation Functions
bool replace(Array * const arr, int value);
bool replaceFunc(Array * const arr, pred_t pred);
bool replaceFirst(Array * const arr, int value);
bool replaceFirstFunc(Array * const arr, pred_t pred);
bool replaceLast(Array * const arr, int value);
bool replaceLastFunc(Array * const arr, pred_t pred);
bool replaceFrom(Array * const arr, int from, int value);
bool replaceFromFunc(Array * const arr, int from, pred_t pred);
// Element Manipulation Functions
// Function Declarations
