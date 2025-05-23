// RUN: %check_clang_tidy %s misra-c2023-adv-2.4 %t -- -- -std=c90
// RUN: %check_clang_tidy %s misra-c2023-adv-2.4 %t -- -- -std=c99
// RUN: %check_clang_tidy %s misra-c2023-adv-2.4 %t -- -- -std=c11

enum color2 { RED2, GREEN2, BLUE2 }; /* Not compliant */

void f_enum(void) {
  enum color { RED, GREEN, BLUE }; /* Not compliant */
// CHECK-MESSAGES: :[[@LINE-1]]:8: warning: unused tag 'color' [misra-c2023-adv-2.4]

  enum status { OK, FAIL };        /* Compliant - Used below. */

  enum status test = OK;

  typedef enum ready {             /* Not compliant */
// CHECK-MESSAGES: :[[@LINE-1]]:8: warning: unused tag 'ready' [misra-c2023-adv-2.4]  
    INIT, 
    READY, 
    WAIT 
  } ready_t;

  ready_t r = INIT;
}

void f(enum color2 *c) {
}

