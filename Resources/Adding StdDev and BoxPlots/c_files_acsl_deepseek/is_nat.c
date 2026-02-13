/*@ assigns \nothing;
    ensures \result == 1 <==> x3 >= 0;
    ensures \result == 0 <==> x3 < 0;
*/
int is_nat(int  x3) {
  int x5 = x3 >= 0;
  return x5;
}
