#include <limits.h>

/*@
  ensures \result == (x0 > 0);
*/
int is_pos(int x0) {
  return x0 > 0;
}

/*@
  ensures \result == (x3 >= 0);
*/
int is_nat(int x3) {
  return x3 >= 0;
}

/*@
  ensures \result == x6 - 1;
*/
int minus1(int x6) {
  return x6 - 1;
}

