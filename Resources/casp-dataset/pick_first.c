/*@
  requires \valid(p);
  assigns \nothing;
  ensures \result == p[0];
*/
int pick_first(int* p) {
  return p[0];
}