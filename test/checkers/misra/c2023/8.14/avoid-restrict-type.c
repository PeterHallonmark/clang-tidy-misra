// RUN: %check_clang_tidy %s misra-c2023-req-8.14 %t -- -- -std=c11

void f(int *restrict ptr) {
  // CHECK-MESSAGES: :[[@LINE-1]]:8: warning: Avoid restrict type [misra-c2023-req-8.14]
}

void g(char *restrict ptr) {
  // CHECK-MESSAGES: :[[@LINE-1]]:8: warning: Avoid restrict type [misra-c2023-req-8.14]
}
