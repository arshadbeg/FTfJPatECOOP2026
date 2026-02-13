/*
  @ requires a1 != NULL;
  @ requires a2 != NULL;
  @ requires an1 != NULL;
  @ requires an2 != NULL;
  @ requires n1 >= 0;
  @ requires n2 >= 0;
  @ ensures 
      ((n1 != n2) ==> \result == 0) 
      && 
      ((n1 == n2) ==> 
          (\forall integer i; 0 <= i < n1 ==> eq_VC(a1[i], a2[i], an1[i], an2[i]) == 1) 
          ==> \result == 1 
          && 
          (\exists integer i; 0 <= i < n1 && eq_VC(a1[i], a2[i], an1[i], an2[i]) != 1) 
          ==> \result == 0
      );
  // Or more simply:
  @ ensures \result == 1 <==> (n1 == n2 && \forall integer i; 0 <= i < n1 ==> eq_VC(a1[i], a2[i], an1[i], an2[i]) == 1);
  @ ensures \result == 0 <==> (n1 != n2 || \exists integer i; 0 <= i < n1 && eq_VC(a1[i], a2[i], an1[i], an2[i]) != 1);
*/
int eq_VVC(char **a1, char **a2, int *an1, int *an2, int n1, int n2) {
  if (n1 != n2) return 0;
  for (int i = 0; i < n1; i++) {
    if (eq_VC(a1[i], a2[i], an1[i], an2[i]) != 1) return 0;
  }
  return 1;
}
