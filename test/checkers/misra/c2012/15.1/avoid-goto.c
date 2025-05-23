// RUN: %check_clang_tidy %s misra-c2012-adv-15.1 %t -- -- -std=c90
// RUN: %check_clang_tidy %s misra-c2012-adv-15.1 %t -- -- -std=c99
// RUN: %check_clang_tidy %s misra-c2012-adv-15.1 %t -- -- -std=c11

void f(void) {
  goto LabelG;
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: avoid goto statement [misra-c2012-adv-15.1]
LabelG:
  while(1);
}
