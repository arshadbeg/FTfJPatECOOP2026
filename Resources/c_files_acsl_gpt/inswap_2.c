/*@
  requires \valid(x0 + (0 .. x1)) && \valid(x0 + (0 .. x2));
  assigns x0[x1], x0[x2];
  ensures x0[x1] == \old(x0[x2]);
  ensures x0[x2] == \old(x0[x1]);
  ensures (\forall integer k; k != x1 && k != x2 ==> x0[k] == \old(x0[k]));
*/
void inswap(int *x0, int x1, int x2) {
  int x4 = x0[x1];
  int x5 = x0[x2];
  x0[x1] = x5;
  x0[x2] = x4;
}

