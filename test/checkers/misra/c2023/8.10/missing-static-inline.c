// RUN: %check_clang_tidy %s misra-c2023-req-8.10 %t -- -std=c99
// RUN: %check_clang_tidy %s misra-c2023-req-8.10 %t -- -std=c11

inline int f() { 
// CHECK-MESSAGES: :[[@LINE]]:1: warning: inline function shall be static [misra-c2023-req-8.10]
  return 42;
}

static inline int g() {
  return 0;
}
