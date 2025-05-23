// RUN: %check_clang_tidy %s misra-c2023-adv-15.1 %t -- -- -std=c90
// RUN: %check_clang_tidy %s misra-c2023-adv-15.1 %t -- -- -std=c99
// RUN: %check_clang_tidy %s misra-c2023-adv-15.1 %t -- -- -std=c11
	
void f(void) {
  goto Label1;    /* Non compliant */
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: avoid goto statement [misra-c2023-adv-15.1]
Label1:
}

void g(void) {
Label2:
  goto Label2;    /* Non compliant */
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: avoid goto statement [misra-c2023-adv-15.1]
}
