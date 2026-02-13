/*@ requires \valid_function(e);
    requires \valid_function(d);
    assigns \nothing;
    ensures \result == d(e(i));
*/
int de(int i) {
  return d(e(i));
}
