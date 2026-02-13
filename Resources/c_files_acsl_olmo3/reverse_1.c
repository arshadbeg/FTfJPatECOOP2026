// ACSL annotation for reverse.c
/*
@requires a != NULL;
@requires res != NULL;
@requires \valid(a[0..size-1]);
@requires \valid(res[0..size-1]);
@requires size >= 0;
@assigns res[0..size-1];
@ensures \forall i. 0 <= i < size ==> res[i] == a[size - i - 1];
*/

// @function reverse
// @ensures res is the reverse of a[0..size-1];
void reverse(int a[], int res[], int size) {
  //@ assume a != NULL && res != NULL && \valid(a[0..size-1]) && \valid(res[0..size-1]) && size >= 0;
  int i;
  for (i = size - 1; i >= 0; --i) {
    //@ invariant 0 <= i < size
    //@ assert At each step, res[i] will be set to a[size - i - 1];
    res[i] = a[size - i - 1];
  }
}
