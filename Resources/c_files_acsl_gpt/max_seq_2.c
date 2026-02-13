/*@ 
  requires t != \null;
  assigns \nothing;
  ensures \result == -1 <==> len <= 0;
  ensures len > 0 ==> (\exists int i; 0 <= i < len && t[i] == \result && 
                        (\forall int j; 0 <= j < len ==> t[i] >= t[j]));
*/
int max_seq(unsigned int *t, int len) {
    if (len <= 0) return -1;
    return t[max_idx(t, len)];
}

