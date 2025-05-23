// RUN: %check_clang_tidy %s misra-c2023-adv-2.3 %t -- -- -std=c90
// RUN: %check_clang_tidy %s misra-c2023-adv-2.3 %t -- -- -std=c99
// RUN: %check_clang_tidy %s misra-c2023-adv-2.3 %t -- -- -std=c11

#include <stdint.h>

typedef int16_t type1;  /* Not compliant */
// CHECK-MESSAGES: :[[@LINE-1]]:17: warning: unused type declaration 'type1' [misra-c2023-adv-2.3]
typedef int32_t type2;  /* Compliant */


void f(void) {
  typedef int8_t type3;  /* Not compliant */
// CHECK-MESSAGES: :[[@LINE-1]]:18: warning: unused type declaration 'type3' [misra-c2023-adv-2.3]
}

void g(void) {
  typedef uint8_t type4; /* Complaint */
  type2 x;
  type4 y;
}
