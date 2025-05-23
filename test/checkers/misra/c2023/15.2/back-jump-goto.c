// RUN: %check_clang_tidy %s misra-c2023-req-15.2 %t -- -- -std=c90
// RUN: %check_clang_tidy %s misra-c2023-req-15.2 %t -- -- -std=c99
// RUN: %check_clang_tidy %s misra-c2023-req-15.2 %t -- -- -std=c11

void f(void) {
  goto Label1;    /* Compliant */
Label1:
}

void g(void) {
Label2:
  goto Label2;    /* Non compliant */
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: goto statement jumps backward to label 'Label2' [misra-c2023-req-15.2]
}
