// ACSL annotation for max_idx.c
/*
@requires t != NULL && len >= 0;
@ensures \result == (\forall i. 0 <= i < len - 1 ==> t[max] >= t[i]) 
         && (\exists m. \result == m 
             && (\forall i. 0 <= i < len ==> (t[m] >= t[i]) )
             && (0 <= \result < len));
@ensures \result == 0 && len <= 1; // If len <= 1, returns 0
@assigns nothing;
*/

// @function max_idx
// @ensures \result is the index of the maximum element in t[0..len-1];
// @ensures if len <= 1, \result == 0;
int max_idx(unsigned int *t, int len) {
  //@ assume t != NULL && len >= 0;
  int max = 0; //@ invariant 0 <= max < len;

  //@ loop invariant 0 <= i <= len
  //@ loop invariant t[max] >= t[0] && (\forall j. 0 < j < i ==> t[max] >= t[j])
  for (int i = 1; i < len; i++) {
    //@ assume 0 <= i < len;
    if (t[max] < t[i]) {
      max = i;
      //@ assert 0 <= max < len;
    }
  }
  //@ assert (\forall j. 0 <= j < len ==> t[max] >= t[j]);
  return max;
}
