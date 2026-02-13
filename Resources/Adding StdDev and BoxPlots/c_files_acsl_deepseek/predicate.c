/*@ assigns \nothing;
    ensures \result == 1 <==> v % 2 == 0;
    ensures \result == 0 <==> v % 2 != 0;
    ensures \result == 0 || \result == 1;
*/
int predicate(int v) {
  return v % 2 == 0;
}
