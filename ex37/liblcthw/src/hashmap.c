#undef NDEBUG
#include <stdint.h>
#include <hashmap.h>
#include <dbg.h>
#include <bstrlib.h>

static int default_compare(void *a, void *b)
{
  return bstrcmp((bstring)a, (bstring)b);
}

/**
 * Simple
