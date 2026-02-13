/*@
  requires p <= r;
  requires \valid(A + (p .. r));
  assigns A[p .. r];
  ensures p <= \result <= r;
  ensures (\forall integer k; p <= k <= \result ==> A[k] <= A[\result]);
  ensures (\forall integer k; \result+1 <= k <= r ==> A[k] > A[\result]);
*/
int partition(int *A, int p, int r) {
  int x = A[r];
  int i = p - 1;
  int tmp;
  for(int j = p; j < r; j++) {
    if(A[j] <= x) {
      i++;
      tmp = A[i];
      A[i] = A[j];
      A[j] = tmp;
    }
  }
  tmp = A[i+1];
  A[i+1] = A[r];
  A[r] = tmp;
  return i+1;
}

