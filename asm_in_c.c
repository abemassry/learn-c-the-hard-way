#include <stdio.h>

int main() {
  // Add 10 and 20 and store result into register %eax
  __asm__ ( "movl, $10, %eax;"
            "movl, $20, %ebx;"
            "addl %ebx, %eax;"
  );

  return 0;
}
