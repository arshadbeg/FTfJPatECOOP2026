// ACSL annotation for while.c
/*
@requires u != NULL;
@requires size >= 0;
@ensures \result == (\max_{0 <= i < size} i such that u[i] is maximal);
@ensures \result == m 
          && (\forall i. 0 <= i < size ==> u[m] >= u[i]);
@assigns nothing;
*/

int find_max_index(int u[], int size) {
  //@ assume u != NULL && size >= 0;
  int max = 0; //@ invariant 0 <= max < i && u[max] >= u[0..i-1]
  int i = 0;
  //@ loop invariant 0 <= i <= size
  //@ loop invariant (\forall k. 0 <= k < i ==> u[max] >= u[k])
  while (i < size) {
    //@ invariant 0 <= i <= size
    if (u[i] > u[max]) {
      max = i;
      //@ assert After update, u[max] >= u[0..i]
    }
    i++;
  }
  //@ assert (\forall k. 0 <= k < size ==> u[max] >= u[k])
  return max;
}
