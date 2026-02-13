/*@ requires n1 >= 0 && n2 >= 0;
    requires \valid(a1 + (0..n1-1)) && \valid(a2 + (0..n2-1));
    assigns \nothing;
    ensures \result == 0 || \result == 1;
    ensures \result == 1 <==> (n1 == n2 && (\forall integer i; 0 <= i < n1 ==> a1[i] == a2[i]));
*/
int eq_VC(char *a1, char *a2, int n1, int n2) {
  if (n1 != n2) return 0;
    
    /*@ loop invariant 0 <= i <= n1;
        loop invariant \forall integer j; 0 <= j < i ==> a1[j] == a2[j];
        loop assigns i;
        loop variant n1 - i;
    */
    for (int i = 0; i < n1; i++) {
      if (a1[i] != a2[i]) return 0;
    }
    return 1;
}
