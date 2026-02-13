/*@ 
  requires t != \null;
  requires n > 0;
  assigns \nothing;
  ensures 0 <= \result < n;
  ensures (\forall int k; 0 <= k < n ==> t[\result] <= t[k]);
*/
int min(int * t, int n) {
    int minInd = 0, i = 0;
    for (i = 1; i < n; i++) {
        if (t[i] < t[minInd])
            minInd = i;
    }
    return minInd;
}

