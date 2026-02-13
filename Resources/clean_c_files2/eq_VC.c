
// Contract and implementation for Vector[Char] equality

int eq_VC(char *a1, char *a2, int n1, int n2) {
  if (n1 != n2) return 0;
    
    for (int i = 0; i < n1; i++) {
      if (a1[i] != a2[i]) return 0;
    }
    return 1;
}
// Contract and implementation for Vector[Vector[Char]] equality

int eq_VVC(char **a1, char **a2, int *an1, int *an2, int n1, int n2) {
  if (n1 != n2) return 0;
    
    for (int i = 0; i < n1; i++) {
      if (eq_VC(a1[i],a2[i],an1[i],an2[i]) != 1) return 0;
    }
    return 1;
}