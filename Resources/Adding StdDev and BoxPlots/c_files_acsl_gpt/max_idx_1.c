/*@ 
  requires t != \null;
  requires len > 0;
  assigns \nothing;
  ensures 0 <= \result < len;
  ensures (\forall int k; 0 <= k < len ==> t[\result] >= t[k]);
*/
int max_idx(unsigned int *t, int len) {
    int max = 0;
    for(int i = 1; i < len; i++)
        if (t[max] < t[i])
            max = i;
    return max;
}

