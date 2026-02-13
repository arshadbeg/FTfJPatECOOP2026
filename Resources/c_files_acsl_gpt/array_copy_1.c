/*@
  requires n >= 0;
  requires \valid(src + (0 .. n-1));
  requires \valid(dst + (0 .. n-1));
  assigns dst[0 .. n-1];
  ensures \forall integer i; 0 <= i < n ==> dst[i] == src[i];
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

