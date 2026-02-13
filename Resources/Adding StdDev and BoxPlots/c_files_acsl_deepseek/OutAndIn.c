/*@ requires \valid(i) && \valid(o);
    requires i != o; // prevent aliasing issues
    assigns *o;
    ensures *o == \old(*i);
    ensures *i == \old(*i);
*/
void OutAndIn(int *i, int *o) {
  *o = *i;
}
