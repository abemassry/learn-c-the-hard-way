#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  system("echo 'dude its running'"); 
  system("sleep 2");
  system("echo 'dude it stopped'"); 
  return 0;
}
