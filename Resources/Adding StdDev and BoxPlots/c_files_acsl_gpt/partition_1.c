/*@ 
  requires A != \null;
  requires p <= r;
  assigns A[p..r];
  ensures p <= \result <= r;
  ensures (\forall int i; p <= i < \result ==> A[i] <= A[\result]);
  ensures (\forall int i; \result < i <= r ==> A[i] >= A[\result]);
*/
int partition (int A[], int p, int r) { 
    int x = A[r]; 
    int tmp, j, i = p-1;
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

