/*@
  requires \valid(i);
  requires \valid(o);
  assigns *o;
  ensures *o == *i;
*/
void OutAndIn(int *i, int *o) {
  *o = *i;
}

