/*@ requires \valid_function(d);
    requires \valid_function(e);
    assigns \nothing;
    ensures \result == e(d(c));
*/
char ed(char c) {
  return e(d(c));
}
