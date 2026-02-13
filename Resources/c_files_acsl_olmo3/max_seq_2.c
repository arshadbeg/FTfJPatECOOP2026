// ACSL annotation for max_seq.c
/*
@requires t != NULL && len >= 0;
@ensures \result == -1 <==> (len <= 0);
@ensures \result == t[max_idx(t, len)] && (len > 0);
@ensures \result == t[m] 
         && (\forall i. 0 <= i < len ==> t[m] >= t[i]) 
         && (0 <= m < len) 
         whenever (len > 0);
@assigns nothing;
*/

// @function max_seq
// @ensures if len <= 0 then \result == -1;
// @ensures if len > 0 then \result == maximum value in t[0..len-1];
int max_seq(unsigned int *t, int len) {
  //@ assume t != NULL && len >= 0;
  if (len <= 0) {
    return -1;
  }
  //@ assume 0 < len;
  return t[max_idx(t, len)];
}
