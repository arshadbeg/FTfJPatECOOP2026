/*@
  requires N >= 0;
  requires \valid(x + (0 .. N-1));
  assigns \nothing;
  ensures 0 <= \result <= N;
  ensures \forall integer i, j;
            0 <= i < j <= N &&
            (\forall integer k; i <= k < j ==> x[k] == x[i])
            ==> \result >= j - i;
*/
int countSameConsecutive(int N, int x[]) {
  int best = 0, i = 0;

  /*@
    loop invariant 0 <= i <= N;
    loop invariant 0 <= best <= N;
    loop invariant \forall integer p, q;
        0 <= p < q <= i &&
        (\forall integer k; p <= k < q ==> x[k] == x[p])
        ==> best >= q - p;
    loop assigns i, best;
    loop variant N - i;
  */
  while (i < N) {
    int j = i + 1;

    /*@
      loop invariant i+1 <= j <= N;
      loop invariant \forall integer k; i <= k < j ==> x[k] == x[i];
      loop assigns j;
      loop variant N - j;
    */
    while (j < N && x[j] == x[i]) ++j;

    if (j - i > best) best = j - i;
    i = j;
  }
  return best;
}

