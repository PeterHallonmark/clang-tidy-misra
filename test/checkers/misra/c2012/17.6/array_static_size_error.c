// RUN: %check_clang_tidy %s misra-c2012-adv-15.1 %t -- -- -std=c99

// Note: 'misra-c2012-adv-15.1' is a dummy check name for this example.
// We're just verifying that clang's error still shows up during clang-tidy invocation.

void f() {
  int array[static 20]; // expected-error{{'static' used in array declarator outside of function prototype}}
}
