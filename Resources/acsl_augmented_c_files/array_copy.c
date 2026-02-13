
void array_copy(int *src, int *dst, int n) {
    if (src < dst) {
        // recopier de droite à gauche
        
        /*@
	loop invariant 0<=i<=None-1;
	loop assigns i, ;
*/
for (int i = n-1; -1 < i; i--) {
            dst[i] = src[i];
        }
    } else {
        // recopier de gauche à droite
        
        /*@
	requires n>0;
	loop invariant 0<=i<=n-1;
	loop assigns i, ;
	loop variant n-1-i;
*/
for (int i = 0; i < n; i++) {
            dst[i] = src[i];
        }
    }
}