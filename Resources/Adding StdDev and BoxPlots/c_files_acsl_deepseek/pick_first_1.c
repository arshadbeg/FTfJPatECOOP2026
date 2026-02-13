/*@ requires \valid(p);
    assigns \nothing;
    ensures \result == *p;
*/
int pick_first(int* p) {
  return p[0];
}
