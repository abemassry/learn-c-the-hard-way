#include "minunit.h"
#include <../src/radixmap.h>
#include <time.h>

static int make_random(RadixMap *map)
{
  size_t i = 0;

  for (i = 0; i < map->max - 1; i++) {
    uint32_t key = (uint32_t)(rand() | (rand() << 16));
    check(RadixMap_add(map, key, 1) == 0, "Failed to add key %u.", key);
  }

  return i;

error:
  return 0;
}

static int check_order(RadixMap *map)
{ 
  RMElement d1, d2;
  unsigned int i = 0;

  // only signal errors if any (should not be)
  for (i = 0; map->end > 0 && i < map->end-1; i++) {
    d1 = map->contents[i];
    d2 = map->contents[i+1];

    if(d1.data.key > d2.data.key) {
      debug("FAIL:i=%u, key: %u, vlaue: %u, equals max? %d\n", i, d1.data.key, d1.data.value,
              d2.data.key == UINT32_MAX);
      return 0;
    }
  }

  return 1;
}

static int test_search(RadixMap *map)
{
  
