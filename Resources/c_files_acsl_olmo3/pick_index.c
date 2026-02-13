// ACSL annotation for pick_first.c
/*
@requires p != NULL;
@requires \valid(p[0]); // At least one element must exist
@ensures \result == p[0];
@assigns nothing;
*/

// @function pick_first
// @ensures \result == first element of p;
int pick_first(int* p) {
  //@ assume p != NULL && \valid(p[0]);
  return p[0];
}
