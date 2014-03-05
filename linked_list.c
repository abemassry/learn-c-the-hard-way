#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
  int val;
  struct ListNode *next;
} ListNode;

typedef struct List {
  int count;
  ListNode *first;
  ListNode *last;
} List;

int main()
{

  ListNode *head = NULL;
  head = malloc(sizeof(ListNode));
  if (head == NULL) {
    return 1;
  }

  return 0;
}
