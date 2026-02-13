// Contract and implementation for Vector[Char] equality

/*@ requires n1 >= 0 && n2 >= 0;
    requires \valid(a1 + (0..n1-1)) && \valid(a2 + (0..n2-1));
    assigns \nothing;
    ensures \result == 0 || \result == 1;
    ensures \result == 1 <==> (n1 == n2 && (\forall integer i; 0 <= i < n1 ==> a1[i] == a2[i]));
    ensures \result == 0 <==> (n1 != n2 || (\exists integer i; 0 <= i < n1 && a1[i] != a2[i]));
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

// Contract and implementation for Vector[Vector[Char]] equality

/*@ requires n1 >= 0 && n2 >= 0;
    requires \valid(a1 + (0..n1-1)) && \valid(a2 + (0..n2-1));
    requires \valid(an1 + (0..n1-1)) && \valid(an2 + (0..n2-1));
    requires \forall integer i; 0 <= i < n1 ==> \valid(a1[i] + (0..an1[i]-1));
    requires \forall integer i; 0 <= i < n2 ==> \valid(a2[i] + (0..an2[i]-1));
    assigns \nothing;
    ensures \result == 0 || \result == 1;
    ensures \result == 1 <==> (n1 == n2 && (\forall integer i; 0 <= i < n1 ==> 
            an1[i] == an2[i] && (\forall integer j; 0 <= j < an1[i] ==> a1[i][j] == a2[i][j])));
*/
int eq_VVC(char **a1, char **a2, int *an1, int *an2, int n1, int n2) {
  if (n1 != n2) return 0;
    
    /*@ loop invariant 0 <= i <= n1;
        loop invariant \forall integer j; 0 <= j < i ==> 
                eq_VC(a1[j], a2[j], an1[j], an2[j]) == 1;
        loop assigns i;
        loop variant n1 - i;
    */
    for (int i = 0; i < n1; i++) {
      if (eq_VC(a1[i],a2[i],an1[i],an2[i]) != 1) return 0;
    }
    return 1;
}
