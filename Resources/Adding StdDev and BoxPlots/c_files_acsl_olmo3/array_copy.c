/*
  @ requires src != NULL;
  @ requires dst != NULL;
  @ requires n >= 0;
  @ ensures \forall integer i; 0 <= i < n ==> dst[i] == \old(src[i]);
  @ ensures \forall integer i; i >= n ==> dst[i] == \old(dst[i]);
  // Optional: If you want to specify that the order of copying is as implemented
  // (but ACSL does not require you to specify how, only what the result is)
*/
void array_copy(int *src, int *dst, int n) {
    // @ loop invariant 0 <= i < n - 1  [for the forward loop]
    // @ loop invariant dst[i+1 ... n-1] == \old(dst[i+1 ... n-1])
    // @ loop invariant dst[0 ... i] == \old(dst[0 ... i])
    // But we'll keep it simple unless you want detailed loop invariants.

    if (src < dst) {
        // Copy from right to left to avoid overwriting not-yet-copied data
        // @ loop invariant n-1 - i >= 0
        // @ loop invariant \forall integer k; n-1 - i <= k < n ==> dst[k] == \old(src[k])
        for (int i = n-1; -1 < i; i--) {
            dst[i] = src[i];
        }
    } else {
        // Copy from left to right
        // @ loop invariant 0 <= i <= n
        // @ loop invariant \forall integer k; 0 <= k < i ==> dst[k] == \old(src[k])
        for (int i = 0; i < n; i++) {
            dst[i] = src[i];
        }
    }
}
