/*@ assigns \nothing;
    ensures \result == 1 <==> x0 > 0;
    ensures \result == 0 <==> x0 <= 0;
*/
int is_pos(int  x0) {
  int x2 = x0 > 0;
  return x2;
}

/*@ assigns \nothing;
    ensures \result == 1 <==> x3 >= 0;
    ensures \result == 0 <==> x3 < 0;
*/
int is_nat(int  x3) {
  int x5 = x3 >= 0;
  return x5;
}
