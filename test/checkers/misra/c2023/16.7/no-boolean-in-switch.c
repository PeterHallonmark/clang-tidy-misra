// RUN: %check_clang_tidy %s misra-c2023-req-16.7 %t -- -- -std=c90
// RUN: %check_clang_tidy %s misra-c2023-req-16.7 %t -- -- -std=c99
// RUN: %check_clang_tidy %s misra-c2023-req-16.7 %t -- -- -std=c11

#include <stdbool.h>

void testSwitchWithBoolean() {
  bool flag = true;

  // Test direct boolean variable
  switch (flag) {  // Non-compliant
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: avoid boolean expression in switch statement [misra-c2023-req-16.7]
    case true:
      break;
    case false:
      break;
  }

  // Test logical NOT operation
  switch (!flag) {  // Non-compliant
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: avoid boolean expression in switch statement [misra-c2023-req-16.7]
    case true:
      break;
    default:
      break;
  }

  // Test comparison operation
  int x = 5;
  switch (x == 0) {  // Non-compliant
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: avoid boolean expression in switch statement [misra-c2023-req-16.7]
    case true:
      break;
    case false:
      break;
  }

  // Test logical OR operation
  int y = 10;
  switch ((x == 5) || (y == 10)) {  // Non-compliant
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: avoid boolean expression in switch statement [misra-c2023-req-16.7]
    case true:
      break;
    case false:
      break;
  }

  // Test logical AND operation
  switch ((x > 0) && (y < 20)) {  // Non-compliant
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: avoid boolean expression in switch statement [misra-c2023-req-16.7]
    case true:
      break;
    case false:
      break;
  }

  // Test parenthesized boolean expression
  switch ((x != 10)) {  // Non-compliant
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: avoid boolean expression in switch statement [misra-c2023-req-16.7]
    case true:
      break;
    case false:
      break;
  }

  // Test ternary operator returning boolean
  switch ((x > 0) ? true : false) {  // Non-compliant
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: avoid boolean expression in switch statement [misra-c2023-req-16.7]
    case true:
      break;
    case false:
      break;
  }

  // Test explicitly cast boolean to int
  switch ((int)(x == 5)) {  // Compliant (allowed since cast forces integer type)
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: avoid boolean expression in switch statement [misra-c2023-req-16.7]
    case 0:
      break;
    case 1:
      break;
  }

  // Test correct integer switch case
  switch (x) {  // Compliant
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: avoid boolean expression in switch statement [misra-c2023-req-16.7]
    case 5:
      break;
    case 10:
      break;
  }
}
