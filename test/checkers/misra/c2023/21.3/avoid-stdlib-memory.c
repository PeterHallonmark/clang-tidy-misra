// RUN: %check_clang_tidy %s misra-c2023-req-21.5 %t -- -- -std=c90

#include <stdlib.h>

void example() {
  void *ptr1 = malloc(100);
  // CHECK-MESSAGES: :[[@LINE-1]]:14: warning: Avoid function 'malloc' [misra-c2023-req-21.3]

  void *ptr2 = calloc(10, 10);
  // CHECK-MESSAGES: :[[@LINE-1]]:14: warning: Avoid function 'calloc' [misra-c2023-req-21.3]

  void *ptr3 = realloc(ptr1, 200);
  // CHECK-MESSAGES: :[[@LINE-1]]:14: warning: Avoid function 'realloc' [misra-c2023-req-21.3]

  void *ptr4 = aligned_alloc(16, 100);
  // CHECK-MESSAGES: :[[@LINE-1]]:14: warning: Avoid function 'aligned_alloc' [misra-c2023-req-21.3]

  free(ptr1);
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: Avoid function 'free' [misra-c2023-req-21.3]

  free(ptr2);
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: Avoid function 'free' [misra-c2023-req-21.3]

  free(ptr3);
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: Avoid function 'free' [misra-c2023-req-21.3]

  free(ptr4);
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: Avoid function 'free' [misra-c2023-req-21.3]
}
