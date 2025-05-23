// RUN: %check_clang_tidy %s misra-c2023-req-11.3 %t -- -- -std=c90
// RUN: %check_clang_tidy %s misra-c2023-req-11.3 %t -- -- -std=c99
// RUN: %check_clang_tidy %s misra-c2023-req-11.3 %t -- -- -std=c11

#include <stddef.h>

void test() {
    int *p1 = 0;          // Not compliant
    int *p2 = (void *)0;  // Compliant
    int *p3 = NULL;       // Compliant

    if (p1 == 0) { }         // Non-compliant
    if (p2 == (void *)0) { } // Compliant
    if (p3 == NULL) { }      // Compliant

    p1 = (1 - 1);    // Non-compliant
    p2 = (void *)0;  // Compliant

    p1 = (p2 == NULL) ? p3 : 0;  // Non-compliant
    p2 = (p1 == 0) ? NULL : p3;  // Non-compliant
}
