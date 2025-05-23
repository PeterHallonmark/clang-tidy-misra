// RUN: %clang_tidy %s misra-c2023-adv-20.5 %t -- -std=c90 -I %S
// RUN: %clang_tidy %s misra-c2023-adv-20.5 %t -- -std=c99 -I %S
// RUN: %clang_tidy %s misra-c2023-adv-20.5 %t -- -std=c11 -I %S

#include header1.h  expected-error{{expected "FILENAME" or <FILENAME>}}

int main(void)
{
  return 0;
}
