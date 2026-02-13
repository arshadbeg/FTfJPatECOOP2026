// ACSL annotation for max_ptr_3.c
/*
@requires a != NULL && b != NULL;
@ensures \result == ((@old(*a) > @old(*b)) ? @old(*a) : @old(*b));
@assigns nothing;
*/

int max_ptr(int* a, int* b) {
  //@ assume a != NULL && b != NULL;
  return (*a > *b) ? *a : *b;
}

// main function usage
int main() {
  //@ assume true;
  h = 42;
  int a = 24, b = 42;
  int x = max_ptr(&a, &b); //@ ensures x == 42;
  //@ assert x == 42;
  return 0;
}
