/*@ requires \valid(x0 + (0..\max(x1, x2)));
    requires x1 >= 0 && x2 >= 0;
    assigns x0[x1], x0[x2];
    ensures x0[x1] == \old(x0[x2]);
    ensures x0[x2] == \old(x0[x1]);
    ensures \forall integer i; i != x1 && i != x2 ==> x0[i] == \old(x0[i]);
*/
void inswap(int  * x0, int  x1, int  x2) {
  int x4 = x0[x1];
  int x5 = x0[x2];
  x0[x1] = x5;
  x0[x2] = x4;
}
