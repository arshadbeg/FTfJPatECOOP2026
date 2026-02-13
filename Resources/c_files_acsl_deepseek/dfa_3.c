#include <limits.h>
#include <string.h>

/*@ requires x0 != \null;
    requires \valid(x0);
    assigns \nothing;
    ensures \result == 0 || \result == 1;
    behavior return_true:
      ensures \result == 1 ==> (\forall integer i; 0 <= i ==> x0[i] != '\0') && x3 == 3;
    behavior return_false:
      ensures \result == 0 ==> (\exists integer i; 0 <= i && x0[i] == '\0') || x3 != 3;
*/
int dfa(char  * x0) {
  int x2 = 1/*true*/;
  int x3 = 0;
  
  char  *x5 = x0;
  
  /*@ loop invariant x5 == x0 || (x5 > x0 && \valid(x5-1));
      loop invariant x2 == 1;
      loop invariant x3 == 0;
      loop assigns x5;
      loop variant \max(0, INT_MAX - (x5 - x0));
  */
  for (;;) {
    char  *x7 = x5;
    char x8 = x7[0];
    int x9 = x8 == '\0';
    int x13;
    if (x9) {
      x13 = 0/*false*/;
    } else {
      int x11 = x2;
      x13 = x11;
    }
    if (!x13) break;
    char  *x39 = x5;
    char  *x40 = x39+1;
    x5 = x40;
    
  }
  char  *x86 = x5;
  char x87 = x86[0];
  int x88 = x87 == '\0';
  int x91;
  if (x88) {
    int x89 = x2;
    x91 = x89;
  } else {
    x91 = 0/*false*/;
  }
  int x95;
  if (x91) {
    int x92 = x3;
    int x93 = x92 == 3;
    x95 = x93;
  } else {
    x95 = 0/*false*/;
  }
  
  return x95;
}
