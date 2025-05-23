// RUN: %check_clang_tidy %s misra-c2023-adv-2.5 %t -- -- -std=c90
// RUN: %check_clang_tidy %s misra-c2023-adv-2.5 %t -- -- -std=c99
// RUN: %check_clang_tidy %s misra-c2023-adv-2.5 %t -- -- -std=c11

#define SIZE 4  /* Compliant */
#define DATA 3  /* Not compliant */
// CHECK-MESSAGES: :[[@LINE-1]]:9: warning: Unused macro definition 'DATA' [misra-c2023-adv-2.5]

int a[SIZE];

#define TEMP 10  /* Compliant - This is due to the undef */
#undef TEMP       

#define TEST 42  /* Not compliant - Not used after redefined. */  
// CHECK-MESSAGES: :[[@LINE-1]]:9: warning: Unused macro definition 'TEST' [misra-c2023-adv-2.5]
