// RUN: %check_clang_tidy %s misra-c2023-req-8.3 %t -- -- -std=c90
// RUN: %check_clang_tidy %s misra-c2023-req-8.3 %t -- -- -std=c99
// RUN: %check_clang_tidy %s misra-c2023-req-8.3 %t -- -- -std=c11

#include <stdint.h>

extern int16_t func(int16_t num, int16_t den);
int16_t func(int16_t den, int16_t num) {  // Not compliant - 'num' vs 'den'
    return num / den;
}


/*
extern void g(const int *p);
void g(int *p) { }  // Not compliant - missing const
*/


typedef uint16_t width_t;
typedef uint16_t height_t;
typedef uint32_t area_t;

extern area_t area(width_t w, height_t h);
area_t area(width_t w, width_t h) {  // Not compliant - height_t vs width_t - does not work...
    return (area_t) w * h;
}



void f(void) {
  goto Label1;    /* Non compliant */
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: avoid goto statement [misra-c2023-adv-15.1]
Label1:
}

