// RUN: %check_clang_tidy %s misra-c2023-req-17.1 %t -- -- -std=c90
// RUN: %check_clang_tidy %s misra-c2023-req-17.1 %t -- -- -std=c99
// RUN: %check_clang_tidy %s misra-c2023-req-17.1 %t -- -- -std=c11

#include <stdarg.h>
// CHECK-MESSAGES: :[[@LINE-1]]:1: warning: Avoid standard header 'stdarg.h' [misra-c2023-req-17.1]

void f(int n, ...) {
  va_list args;
  va_start(args, n);
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: Avoid macro 'va_start' [misra-c2023-req-17.1]

  int val = va_arg(args, int);
  // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: Avoid macro 'va_arg' [misra-c2023-req-17.1]

  va_end(args);
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: Avoid macro 'va_end' [misra-c2023-req-17.1]
}
