/*@ requires n > 0 && \valid(p+ (0..n-1));
    assigns \nothing;
*/
int pick_element(int* p, int n) {
  int i = pick_index(n);
  //@ assert (0 <= i && i < n);
  return p[i];
}