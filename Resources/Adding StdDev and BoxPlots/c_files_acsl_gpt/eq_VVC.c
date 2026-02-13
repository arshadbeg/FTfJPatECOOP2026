/*@
  requires n1 >= 0;
  requires n2 >= 0;
  requires \valid_read(an1 + (0 .. n1-1));
  requires \valid_read(an2 + (0 .. n2-1));
  requires \valid_read(a1 + (0 .. n1-1));
  requires \valid_read(a2 + (0 .. n2-1));
  requires \forall integer i;
            0 <= i < n1 ==> 
              \valid_read(a1[i] + (0 .. an1[i]-1)) &&
              \valid_read(a2[i] + (0 .. an2[i]-1));
  assigns \nothing;
  ensures \result == 1 <==>
          (n1 == n2 &&
           \forall integer i;
             0 <= i < n1 ==>
               eq_VC(a1[i], a2[i], an1[i], an2[i]) == 1);
*/
int eq_VVC(char **a1, char **a2,
           int *an1, int *an2,
           int n1, int n2) {
  if (n1 != n2) return 0;

  for (int i = 0; i < n1; i++) {
    if (eq_VC(a1[i], a2[i], an1[i], an2[i]) != 1) return 0;
  }
  return 1;
}

