
/*@
  ensures (len <= 0) ==> \result==-1;
*/
int max_seq(unsigned int *t, int len) {
  if (len <= 0) return -1;
  return t[max_idx(t, len)];
}