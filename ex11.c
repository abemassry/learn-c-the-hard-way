#include <stdio.h>
//#define NELEMS(x) (sizeof(x) / sizeof(x[0]))

int main(int argc, char *argv[])
{
  // go through each string in argv

  int i = 0;
  while(i < argc) {
    printf("arg %d: %s\n", i, argv[i]);
    i++;
  }

  // let's make our own array of strings
  char *states[] = {
    "California", "Oregon",
    "Washington", "Texas"
  };


  i = 0;
  if (argc > 4) {
    argc = 4;
  }
  while(i < argc) {
    printf("arg %d: %s\n", i, argv[i]);
    states[i] = argv[i];
    i++;
  }

  int num_states = 4 - 1;
  i = 0;  //watch for this
  while(num_states > -1) {
    printf("state %d: %s\n", num_states, states[num_states]);
    num_states--;
  }
  return 0;
}
