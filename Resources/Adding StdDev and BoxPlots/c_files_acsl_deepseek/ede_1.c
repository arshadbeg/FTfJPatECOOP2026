/*@ requires \valid_function(e);
    requires \valid_function(d);
    assigns \nothing;
    ensures \result == e(d(e(i)));
*/
char ede(int i) {
  return e(d(e(i)));
}
