// RUN: %check_clang_tidy %s misra-c2023-adv-15.1 %t -- -- -std=c90
// RUN: %check_clang_tidy %s misra-c2023-adv-15.1 %t -- -- -std=c99
// RUN: %check_clang_tidy %s misra-c2023-adv-15.1 %t -- -- -std=c11

int g(int x);

void f(void) {
  int result = g(10);  // Compliant

  h();                 // Non compliant
}




