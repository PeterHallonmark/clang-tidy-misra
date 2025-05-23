// RUN: %check_clang_tidy %s misra-c2012-req-3.2 %t -- -- -std=c99

// A comment              Compliant

// Another comment \
   with a line splice     Not compliant
// CHECK-MESSAGES: :[[@LINE-2]]:20: warning: avoid line-spliceing within a '//' comment [misra-c2012-req-3.2]

// Another comment \
   with two \
   line splices           Not compliant
// CHECK-MESSAGES: :[[@LINE-3]]:20: warning: avoid line-spliceing within a '//' comment [misra-c2012-req-3.2]
// CHECK-MESSAGES: :[[@LINE-3]]:13: warning: avoid line-spliceing within a '//' comment [misra-c2012-req-3.2]

/\
/\
/\
printf("chrismas tree");  Not compliant
// CHECK-MESSAGES: :[[@LINE-4]]:2: warning: avoid line-spliceing within a '//' comment [misra-c2012-req-3.2]
// CHECK-MESSAGES: :[[@LINE-4]]:2: warning: avoid line-spliceing within a '//' comment [misra-c2012-req-3.2]
// CHECK-MESSAGES: :[[@LINE-4]]:2: warning: avoid line-spliceing within a '//' comment [misra-c2012-req-3.2]

/* \
                          Compliant - block comment '/*' allows line splice
*/
