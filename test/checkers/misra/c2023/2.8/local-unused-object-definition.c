// RUN: %check_clang_tidy %s misra-c2023-adv-2.8 %t -- -- -std=c90
// RUN: %check_clang_tidy %s misra-c2023-adv-2.8 %t -- -- -std=c99
// RUN: %check_clang_tidy %s misra-c2023-adv-2.8 %t -- -- -std=c11


void f() {
  int x;       /* Not complaint */
  // CHECK-MESSAGES: :[[@LINE-1]]:7: warning: unused object definition 'x' [misra-c2023-adv-2.8]
  
  int y = 10;  /* Not Complaint */
  // CHECK-MESSAGES: :[[@LINE-1]]:7: warning: unused object definition 'y' [misra-c2023-adv-2.8]
   
  int z = 20;  /* Compliant    z is used by a and should not be flaged */
  int a = z;

  if (a > 0) {
  }
}
