#include "minunit.h"
#include "../src/bstree.h"
#include <assert.h>
#include "../bstr/bstrlib.h"
#include <stdlib.h>
#include <time.h>

BSTree *map = NULL;
static int traverse_called = 0;
struct tagbstring test1 = bsStatic("test data 1");
struct tagbstring test2 = bsStatic("test data 2");
struct tagbstring test3 = bsStatic("test data 3");
struct tagbstring expect1 = bsStatic("THE VALUE 1");
struct tagbstring expect2 = bsStatic("THE VALUE 2");
struct tagbstring expect3 = bsStatic("THE VALUE 3");

static int traverse_good_cb(BSTreeNode *node)
{
  debug("KEY: %s", bdata((bstring)node->key));
  traverse_called++;
  return 0;
}

static int traverse_fail_cb(BSTreeNode *node)
{
  debug("KEY: %s", bdata((bstring)node->key));
  traverse_called++;

  if(traverse_called == 2) {
    return 1;
  } else {
    return 0;
  }
}

char *test_create()
{
  map = BSTree_create(NULL);
  mu_assert(map != NULL, "Failed to create map.");

  return NULL;
}

char *test_destroy()
{
  BSTree_destroy(map);

  return NULL;
}

char *test_get_set()
{
  int rc = BSTree_set(map, &test1, &expect1);
  mu_assert(rc == 0, "Failed to set &test1");
  bstring result = BSTree_get(map, &test1);
