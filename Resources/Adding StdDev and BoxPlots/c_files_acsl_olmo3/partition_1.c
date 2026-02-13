// ACSL annotation for partition.c
/*
@requires A != NULL;
@requires p <= r && r < \length(A);
@assigns A[p..r];
@ensures \exists q. p <= q <= r 
          && (\forall i. p <= i < q ==> A[i] <= x0)
          && (\forall j. q <= j <= r ==> A[j] >= x0)
          && (\result == q);
@ensures \result is the final partition index;
*/

int partition(int A[], int p, int r) {
  //@ assume A != NULL;
  //@ assume p <= r;
  //@ assume r < \length(A); // If you have a way to express array length

  int x = A[r]; //@ x is the pivot
  int i = p - 1;
  int j;

  //@ loop invariant p <= j <= r
  //@ loop invariant (\forall k. p <= k < i+1 ==> A[k] <= x)
  //@ loop invariant (\forall k. i+1 <= k <= j ==> A[k] > x)
  for (j = p; j < r; j++) {
    if (A[j] <= x) {
      i = i + 1;
      //@ swap A[i] and A[j]
      int tmp = A[i];
      A[i] = A[j];
      A[j] = tmp;
    }
  }
  //@ after loop: A[i+1] and A[r] not yet swapped
  i = i + 1;
  int tmp = A[i];
  A[i] = A[r];
  A[r] = tmp;

  return i; //@ ensures \result == i;
}
