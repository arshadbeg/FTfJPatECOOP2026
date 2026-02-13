/*@ requires n >= 0;
    requires \valid(src + (0..n-1)) && \valid(dst + (0..n-1));
    requires src + n <= dst || dst + n <= src; // arrays don't overlap or overlap safely
    assigns dst[0..n-1];
    ensures \forall integer i; 0 <= i < n ==> dst[i] == src[i];
*/
void array_copy(int *src, int *dst, int n) {
    if (src < dst) {
        // recopier de droite à gauche
        /*@ loop invariant n-1 >= i >= -1;
            loop invariant \forall integer k; i < k < n ==> dst[k] == src[k];
            loop assigns i, dst[0..n-1];
            loop variant i+1;
        */
        for (int i = n-1; -1 < i; i--) {
            dst[i] = src[i];
        }
    } else {
        // recopier de gauche à droite
        /*@ loop invariant 0 <= i <= n;
            loop invariant \forall integer k; 0 <= k < i ==> dst[k] == src[k];
            loop assigns i, dst[0..n-1];
            loop variant n-i;
        */
        for (int i = 0; i < n; i++) {
            dst[i] = src[i];
        }
    }
}
