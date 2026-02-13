/*
  @ requires p <= r;
  @ requires \valid(A + p .. A + r);
  @ requires \valid(A + (r+1));
  @ ensures \exists integer q; p <= q <= r;
      \forall integer i; p <= i < q ==> A[i] <= x;
      \forall integer i; q < i <= r ==> A[i] > x;
      A[q+1] == \old(A[r]);
      \result == q+1;
*/
int if_(int A[], int p, int r, int x) {
  int i = p - 1; // Initialize i
  int j;
  int tmp;
  for (j = p; j < r; j++) {
    if (A[j] <= x) {
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
