/*@
  requires n1 >= 0;
  requires n2 >= 0;
  requires \valid_read(a1 + (0 .. n1-1));
  requires \valid_read(a2 + (0 .. n2-1));
  assigns \nothing;
  ensures \result == 1 <==>
          (n1 == n2 &&
           \forall integer i; 0 <= i < n1 ==> a1[i] == a2[i]);
*/
int eq_VC(char *a1, char *a2, int n1, int n2) {
  if (n1 != n2) return 0;

  for (int i = 0; i < n1; i++) {
    if (a1[i] != a2[i]) return 0;
  }
  return 1;
}

