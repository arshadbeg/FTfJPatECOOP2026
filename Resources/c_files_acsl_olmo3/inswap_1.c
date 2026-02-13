/*
  @ requires x0 != NULL;
  @ requires x1 >= 0;
  @ requires x2 >= 0;
  @ requires x1 < \length(x0);
  @ requires x2 < \length(x0);
  @ ensures x0[x1] == \old(x0[x2]) && x0[x2] == \old(x0[x1]);
*/
void inswap(int *x0, int x1, int x2) {
  int x4 = x0[x1];
  int x5 = x0[x2];
  x0[x1] = x5;
  x0[x2] = x4;
}
