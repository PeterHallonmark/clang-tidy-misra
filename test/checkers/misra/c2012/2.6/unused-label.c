// RUN: %check_clang_tidy %s misra-c2012-adv-2.6 %t -- -- -std=c90
// RUN: %check_clang_tidy %s misra-c2012-adv-2.6 %t -- -- -std=c99
	
void f(void) {
Label1:        /* Not compliant */
// CHECK-MESSAGES: :[[@LINE-1]]:1: warning: unused label 'label1' [misra-c2012-adv-2.6]
}

void g(void) {
  goto Label2;
Label2:        /* Compliant */
}
