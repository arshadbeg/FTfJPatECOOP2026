/*
  @ requires src != NULL;
  @ requires dst != NULL;
  @ requires n >= 0;
  @ ensures \forall integer i; 0 <= i < n ==> dst[i] == \old(src[i]);
  @ ensures \forall integer i; i >= n ==> dst[i] == \old(dst[i]);
*/
void array_copy(int *src, int *dst, int n) {
    if (src < dst) {
        for (int i = n-1; -1 < i; i--) {
            dst[i] = src[i];
        }
    } else {
        for (int i = 0; i < n; i++) {
            dst[i] = src[i];
        }
    }
}
