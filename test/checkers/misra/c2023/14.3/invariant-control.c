// RUN: %check_clang_tidy %s misra-invariant-control %t

void f(int x) {
    if (2 > 3) { // CHECK-MESSAGES: :[[@LINE-1]]:8: warning: MISRA C 2023 Rule 14.3: Controlling expression is invariant
    }

    while (true) { // OK, eftersom det är en oändlig loop
    }

    do { } while (0); // OK, exception enligt MISRA

    for (int i = 0; i < 10; i++) { // OK, i ändras
    }

    if (10 > 5) { // CHECK-MESSAGES: :[[@LINE-1]]:8: warning: Controlling expression is invariant
    }
}
