#include <lcthw/list_algos.h>
#include <lcthw/dbg.h>

inline void ListNode_swap(ListNode *a, ListNode *b)
{
  void *temp = a->value;
  a->value = b->value;
  b->value = temp;
}

int List_bubble_sort(List *list, List_compare cmp)
{
  int sorted = 1;

  if(List_count(list) <= 1) {
    return 0; // already sorted
  }

  do {
    sorted = 1;
    LIST_FOREACH(list, first, next, cur) {
      if(cur->next) {
        if(cmp(cur->value, cur->next->value) > 0) {
          ListNode_swap(cur, cur->next);
          sorted = 0;
        }
      }
    }
  } while(!sorted);

  return 0;
}

inline List *List_merge(List *left, List *right, List_compare cmp)
{
  List *result = List_create();
  void *val = NULL;

  while(List_count(left) > 0 || List_count(right) > 0) {
    if(List_count(left) > 0 && List_count(right) > 0) {
      
