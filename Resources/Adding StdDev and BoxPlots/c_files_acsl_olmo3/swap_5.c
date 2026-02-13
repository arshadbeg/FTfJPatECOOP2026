/*
@requires a != NULL;
@requires b != NULL;
@assigns *a, *b;
@ensures *a == \old(*b) && *b == \old(*a);
*/

// @function swap
// @ensures Swaps the values pointed to by a and b;
void swap(int* a, int* b) {
  //@ assume a != NULL && b != NULL;
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
