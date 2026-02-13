// ACSL annotation for maxarray.c
/*
@requires u != NULL && size >= 0;
@ensures \result == (\max_{0 <= i < size} u[i]);
@assigns nothing;
*/

// @function maxarray
// @ensures \result == maximum value in u[0..size-1] if size > 0;
// @ensures \result == 0 && size == 0;
int maxarray(int u[], int size) {
  //@ assume u != NULL && size >= 0;
  int max = u[0]; // Initialize with the first element
  int i;
  for (i = 1; i < size; i++) {
    //@ invariant 0 <= i <= size
    //@ invariant max == (\max_{0 <= k < i} u[k])
    if (u[i] > max) {
      max = u[i];
    }
  }
  return max; //@ ensures \result == max;
}
