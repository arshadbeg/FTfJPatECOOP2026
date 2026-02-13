/*@ requires \valid_function(d);
    requires \valid_function(e);
    assigns \nothing;
    ensures \result == d(e(d(c)));
*/
int ded(char c) {
  return d(e(d(c)));
}
