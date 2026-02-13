#include <limits.h>
#include <string.h>

/*@ requires x0 != \null;
    requires \valid(x0);
    assigns \nothing;
    ensures \result == 0 || \result == 1;
    behavior return_true:
      ensures \result == 1 ==> (\forall integer i; 0 <= i ==> x0[i] != '\0') && x3 == 2;
    behavior return_false:
      ensures \result == 0 ==> (\exists integer i; 0 <= i && x0[i] == '\0') || x3 != 2;
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
    char  *x37 = x5;
    char  *x38 = x37+1;
    x5 = x38;
    
  }
  char  *x84 = x5;
  char x85 = x84[0];
  int x86 = x85 == '\0';
  int x89;
  if (x86) {
    int x87 = x2;
    x89 = x87;
  } else {
    x89 = 0/*false*/;
  }
  int x93;
  if (x89) {
    int x90 = x3;
    int x91 = x90 == 2;
    x93 = x91;
  } else {
    x93 = 0/*false*/;
  }
  
  return x93;
}
