// RUN: %check_clang_tidy %s misra-c2023-adv-20.5 %t -- -- -std=c99
// RUN: %check_clang_tidy %s misra-c2023-adv-20.5 %t -- -- -std=c11

// Note: 'misra-c2023-adv-20.5' is a dummy check name for this example.
// We're just verifying that clang's error still shows up during clang-tidy invocation.

void f() {
  int array[static 20]; // expected-error{{'static' used in array declarator outside of function prototype}}
}

#define PASS 0
#undef PASS
// CHECK-MESSAGES: :[[@LINE-1]]:8: warning: avoid #undef [misra-c2023-adv-20.5]
