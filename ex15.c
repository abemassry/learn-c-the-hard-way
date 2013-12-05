#include <stdio.h>

// forward declarations
void print_age(int length, int *cur_age, char **cur_name);

//functions
void print_age(int length, int *cur_age, char **cur_name)
{
  int i = 0;
  //cur_age = (char)*names;
  // second way using pointers
  for(i=0; i < length; i++) {
    printf("%s is %d years old.\n",
            *(cur_name+i), *(cur_age+i));
  }
}

int main(int argc, char *argv[])
{
  // create two arrays we care about
  int ages[] = {23, 43, 12, 89, 2};
  char *names[] = {
    "Alan", "Frank",
    "Mary", "John", "Lisa"
  };

  // safely get the size of ages
  int count = sizeof(ages) / sizeof(int);
  int i = 0;

  // first way of using indexing
  for(i = 0; i < count; i++) {
    printf("%s had %d years alive.\n",
            names[i], ages[i]);
  }

  printf("---\n");

  // setup the pointers to the start of the arrays
  int *cur_age = ages;
  char **cur_name = names;

  print_age(count, cur_age, cur_name);

  printf("---\n");

  // third way, pointers are just arrays
  for(i = 0; i < count; i++) {
    printf("%s is %d years old again.\n",
            cur_name[i], cur_age[i]);
  }

  printf("---\n");

  // fourth way with pointers in a stupid complex way
  for(cur_name = names, cur_age = ages;
          (cur_age - ages) < count;
          cur_name++, cur_age++)
  {
    printf("%s lived %d years so far.\n",
            *cur_name, *cur_age);
  }
  
  printf("\n");
  printf("The val using percent d is %d \n", *cur_age);
  printf("The val using percent p is %p \n", cur_age);

  printf("\n");


  return 0;
}
