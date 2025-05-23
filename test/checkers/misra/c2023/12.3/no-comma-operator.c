// RUN: %check_clang_tidy %s misra-c2023-adv-12.3 %t -- -- -std=c90
// RUN: %check_clang_tidy %s misra-c2023-adv-12.3 %t -- -- -std=c99
// RUN: %check_clang_tidy %s misra-c2023-adv-12.3 %t -- -- -std=c11

void test() {
  int a = (1, 2);                               /* non complaint */
  // CHECK-MESSAGES: [[@LINE]]:13: warning: avoid comma operator [misra-c2023-adv-12.3]
  
  for (int i = 0, j = 1; i < 10; ++i, ++j) {    /* Non complaint */
  // CHECK-MESSAGES: [[@LINE]]:37: warning: avoid comma operator [misra-c2023-adv-12.3]
  }
}

