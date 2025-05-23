// RUN: %check_clang_tidy %s misra-c2023-req-17.1 %t -- -- -std=c99
// RUN: %check_clang_tidy %s misra-c2023-req-17.1 %t -- -- -std=c11

#include <stdarg.h>
// CHECK-MESSAGES: :[[@LINE-1]]:1: warning: Avoid standard header 'stdarg.h' [misra-c2023-req-17.1]

void g(int n, ...) {
  va_list args1, args2;
  va_start(args1, n);
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: Avoid macro 'va_start' [misra-c2023-req-17.1]

  va_copy(args2, args1);
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: Avoid macro 'va_copy' [misra-c2023-req-17.1]

  int val = va_arg(args2, int);
  // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: Avoid macro 'va_arg' [misra-c2023-req-17.1]

  va_end(args1);
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: Avoid macro 'va_end' [misra-c2023-req-17.1]

  va_end(args2);
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: Avoid macro 'va_end' [misra-c2023-req-17.1]
}
