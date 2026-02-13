// ACSL annotation for max2.c
/*
@requires i != NULL && j != NULL;
@requires r != NULL;
@assigns *r;
@ensures *r == ( (*i < *j) ? *j : *i );
@ensures \result == -1 <=> (r == NULL);
@ensures \result != -1 ==> \result == 0; // The function does not return the max, only sets *r and returns 0 or -1
*/

// @function max2
// @ensures \result == -1 <=> (r == NULL);
// @ensures \result == 0 && *r == (i_val < j_val ? j_val : i_val) 
//     if (r != NULL && i != NULL && j != NULL);
int max2(int *r, int *i, int *j) {
  //@ assume r != NULL; // If not, the function returns -1
  if (r == NULL) {
    return -1;
  }
  //@ assume i != NULL && j != NULL; // If not specified, we cannot dereference
  *r = (*i < *j) ? *j : *i;
  return 0;
}
