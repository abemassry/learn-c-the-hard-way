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
void *Stack_remove(Stack *stack, StackNode *node);

#define STACK_FOREACH(item, list)\
  for(StackNode *(item) = (list); (item); (item) = (item)->next)

#define Stack_create()\
  return calloc(1, sizeof(Stack))

#define Stack_destroy(A)\
  free(A)

#define Stack_count(A) ((A)->count)

#define Stack_push(list, value){\
  StackNode *node = calloc(1, sizeof(StackNode));\
  check_mem(node);\
  node->value = value;\
  if(list->first == NULL){\
    list->first = node;\
    list->last = node;\
  }else{\
    node->next = list->first;\
    list->first->prev = node;\
    list->first = node;\
  }\
  list->count++;\
error:\
  return;\
}

#define Stack_peek(stack){\
  return stack->first;\
  }

#define Stack_pop(stack){\
  StackNode *node = stack->last;\
  return node != NULL ? Stack_remove(stack, node) : NULL;\
}

#define *Stack_remove(stack, node){\
  void *result = NULL;\
  check(stack->first && stack->last, "Stack is empty.");\


