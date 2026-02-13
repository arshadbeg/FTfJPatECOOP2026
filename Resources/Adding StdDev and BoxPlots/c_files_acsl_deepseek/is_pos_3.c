#include <limits.h>

/*@ assigns \nothing;
    ensures \result == 1 <==> x0 > 0;
    ensures \result == 0 <==> x0 <= 0;
*/
int is_pos(int  x0) {
  int x2 = x0 > 0;
  return x2;
}

/*@ assigns \nothing;
    ensures \result == 1 <==> x3 >= 0;
    ensures \result == 0 <==> x3 < 0;
*/
int is_nat(int  x3) {
  int x5 = x3 >= 0;
  return x5;
}

/*@ requires x6 > INT_MIN; // prevent underflow
    assigns \nothing;
    ensures \result == x6 - 1;
*/
int minus1(int  x6) {
  int x8 = x6 - 1;
  return x8;
}
