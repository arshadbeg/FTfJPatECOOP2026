/*@ ensures \result==0 || \result==1;
    assigns \nothing;
 */
int predicate(int v) {
  return v % 2 == 0;
}