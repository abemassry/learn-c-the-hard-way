#ifndef Stack_h
#define Stack_h

#include <stdlib.h>

struct StackNode;

typedef struct StackNode {
  struct StackNode *next;
  struct StackNode *prev;
  void *value;
} StackNode;

typedef struct Stack {
  int count;
  StackNode *first;
  StackNode *last;
} Stack;

Stack *Stack_create();
void Stack_destroy(Stack *stack);

void Stack_push(Stack *stack, void *value);
void *Stack_pop(Stack *stack);
void Stack_count(Stack *stack);

#define STACK_FOREACH(item, list)\
  for(StackNode *(item) = (list); (item); (item) = (item)->next)

#define Stack_create()\
  return calloc(1, sizeof(Stack))

#define Stack_destroy(A)\
  free(A)

#define 
