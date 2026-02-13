/*@ requires \valid_function(pick_index);
    requires n >= 0;
    requires \valid(p + (0..n-1)) || n == 0;
    assigns \nothing;
    ensures \result == p[pick_index(n)];
*/
int pick_element(int* p, int n) {
  int i = pick_index(n);
  
  return p[i];
}
