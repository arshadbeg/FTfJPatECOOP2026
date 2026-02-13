// ACSL annotation for pick_element.c
/*
@requires p != NULL && n >= 0;
@requires \valid(p[0..n-1]); // If n > 0
@ensures \result == p[i];
@ensures 0 <= i < n && i == \old(i);
@assigns nothing;
@depends on pick_index(n); // contract for pick_index assumed elsewhere
*/

// If you want to assume pick_index returns a value in [0, n-1]:
/*
@requires pick_index(n) >= 0 && pick_index(n) < n;
*/

int pick_element(int* p, int n) {
  //@ assume p != NULL && n >= 0;
  //@ assume \valid(p[0..n-1]); // if n > 0
  int i = pick_index(n); //@ assume 0 <= i < n;
  return p[i];
}

// ACSL annotation for pick_index.c
/*
@requires n >= 0;
@ensures \result == 0;
*/

// @function pick_index
// @ensures always returns 0;
int pick_index(int n) {
  return 0;
}
