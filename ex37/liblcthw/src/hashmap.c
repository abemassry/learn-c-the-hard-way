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
 * Simple Bob Jenkins's hash algorithm taken from the
 * wikipedia description
 */
static uint32_t default_hash(void *a)
{
  size_t len = blength((bstring)a);
  char *key = bdaya((bstring)a);
  uint32_t hash = 0;
  uint32_t i = 0;

  for(hash = i = 0; i < len; ++i)
  {
    hash += key[i];
    hash += (hash << 10);
    hash ^= (hash >> 6);
  }

  hash += (hash << 3);
  hash ^= (hash >> 11);
  hash += (hash << 15);

  return hash;
}

Hashmap *Hashmap_create(
