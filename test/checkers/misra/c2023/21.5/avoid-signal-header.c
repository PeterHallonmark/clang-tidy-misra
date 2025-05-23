// RUN: %check_clang_tidy %s misra-c2023-req-21.5 %t -- -- -std=c90
// RUN: %check_clang_tidy %s misra-c2023-req-21.5 %t -- -- -std=c99
// RUN: %check_clang_tidy %s misra-c2023-req-21.5 %t -- -- -std=c11

#include <stdlib.h>
#include <signal.h>
// CHECK-MESSAGES: :[[@LINE-1]]:1: warning: Avoid standard header 'signal.h' [misra-c2023-req-21.5]

void example() {
  // Makron (om några finns)
  // ...

  // Funktionsanrop till förbjudna funktioner
  void (*signal_handler)(int) = bsd_signal(1, SIG_IGN);
  // CHECK-MESSAGES: :[[@LINE-1]]:29: warning: Avoid function 'bsd_signal' [misra-c2023-req-21.5]

  kill(123, SIGTERM);
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: Avoid function 'kill' [misra-c2023-req-21.5]

  killpg(123, SIGTERM);
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: Avoid function 'killpg' [misra-c2023-req-21.5]

  pthread_kill(pthread_self(), SIGTERM);
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: Avoid function 'pthread_kill' [misra-c2023-req-21.5]

  pthread_sigmask(SIG_BLOCK, NULL, NULL);
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: Avoid function 'pthread_sigmask' [misra-c2023-req-21.5]

  raise(SIGTERM);
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: Avoid function 'raise' [misra-c2023-req-21.5]

  struct sigaction sa;
  sigaction(SIGTERM, NULL, &sa);
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: Avoid function 'sigaction' [misra-c2023-req-21.5]

  sigset_t set;
  sigaddset(&set, SIGTERM);
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: Avoid function 'sigaddset' [misra-c2023-req-21.5]

  sigaltstack(NULL, NULL);
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: Avoid function 'sigaltstack' [misra-c2023-req-21.5]

  sigdelset(&set, SIGTERM);
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: Avoid function 'sigdelset' [misra-c2023-req-21.5]

  sigemptyset(&set);
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: Avoid function 'sigemptyset' [misra-c2023-req-21.5]

  sigfillset(&set);
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: Avoid function 'sigfillset' [misra-c2023-req-21.5]

  sighold(SIGTERM);
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: Avoid function 'sighold' [misra-c2023-req-21.5]

  sigignore(SIGTERM);
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: Avoid function 'sigignore' [misra-c2023-req-21.5]

  siginterrupt(SIGTERM, 1);
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: Avoid function 'siginterrupt' [misra-c2023-req-21.5]

  sigismember(&set, SIGTERM);
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: Avoid function 'sigismember' [misra-c2023-req-21.5]

  signal_handler = signal(1, SIG_IGN);
  // CHECK-MESSAGES: :[[@LINE-1]]:20: warning: Avoid function 'signal' [misra-c2023-req-21.5]

  sigpause(SIGTERM);
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: Avoid function 'sigpause' [misra-c2023-req-21.5]

  sigpending(&set);
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: Avoid function 'sigpending' [misra-c2023-req-21.5]

  sigprocmask(SIG_BLOCK, NULL, NULL);
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: Avoid function 'sigprocmask' [misra-c2023-req-21.5]

  union sigval value;
  sigqueue(123, SIGTERM, value);
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: Avoid function 'sigqueue' [misra-c2023-req-21.5]

  sigrelse(SIGTERM);
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: Avoid function 'sigrelse' [misra-c2023-req-21.5]

  signal_handler = sigset(1, SIG_IGN);
  // CHECK-MESSAGES: :[[@LINE-1]]:20: warning: Avoid function 'sigset' [misra-c2023-req-21.5]

  sigsuspend(&set);
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: Avoid function 'sigsuspend' [misra-c2023-req-21.5]

  siginfo_t info;
  sigtimedwait(&set, &info, NULL);
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: Avoid function 'sigtimedwait' [misra-c2023-req-21.5]

  int sig;
  sigwait(&set, &sig);
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: Avoid function 'sigwait' [misra-c2023-req-21.5]

  sigwaitinfo(&set, &info);
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: Avoid function 'sigwaitinfo' [misra-c2023-req-21.5]
}
