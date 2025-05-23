// RUN: %check_clang_tidy %s misra-c2023-adv-20.5 %t -- -- -std=c90 -I %S
// RUN: %check_clang_tidy %s misra-c2023-adv-20.5 %t -- -- -std=c99 -I %S
// RUN: %check_clang_tidy %s misra-c2023-adv-20.5 %t -- -- -std=c11 -I %S

#include <stdio.h>             // Compliant
#include "header1.h"           // Compliant

#define HEADER2 "header2.h"
#include HEADER2               // Compliant

#include "headers/header3.h"   // Compliant
#include "./headers/header4.h" // Compliant


int main(void)
{
  return 0;
}

#define PASS 0
#undef PASS
// CHECK-MESSAGES: :[[@LINE-1]]:8: warning: avoid #undef [misra-c2023-adv-20.5]

