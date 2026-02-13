/*@ requires x1 > 0 && x3 >= 0 && x3 < x1;
    requires x2 >= 0;
    assigns \nothing;
    ensures \result == x2 * x1 + x3;
    ensures \result >= 0;
*/
int index(int  x0, int  x1, int  x2, int  x3) {
  int x5 = x2 * x1;
  int x6 = x5 + x3;
  return x6;
}
