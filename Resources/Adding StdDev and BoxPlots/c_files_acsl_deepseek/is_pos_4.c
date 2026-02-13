/*@ assigns \nothing;
    ensures \result == 1 <==> x0 > 0;
    ensures \result == 0 <==> x0 <= 0;
*/
int is_pos(int  x0) {
  int x2 = x0 > 0;
  return x2;
}

