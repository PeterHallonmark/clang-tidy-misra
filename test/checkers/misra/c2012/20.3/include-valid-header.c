// RUN: %check_clang_tidy %s misra-c2012-adv-15.1 %t -- -- -std=c90
// RUN: %check_clang_tidy %s misra-c2012-adv-15.1 %t -- -- -std=c99
// RUN: %check_clang_tidy %s misra-c2012-adv-15.1 %t -- -- -std=c11

// Note: 'misra-c2012-adv-15.1' is a dummy check name for this example.
// We're just verifying that clang's error still shows up during clang-tidy invocation.


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
