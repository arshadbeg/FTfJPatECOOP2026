// ACSL annotation for max_ptr_1.c
/*
@requires p != NULL && q != NULL;
@assigns *p, *q;
@ensures (*p >= *q) &&
         ((@old(*p) >= @old(*q)) ? (*p == @old(*p) && *q == @old(*q)) 
          : (*p == @old(*q) && *q == @old(*p)));
*/

void max_ptr(int* p, int* q) {
  //@ assume p != NULL && q != NULL;
  if (*p > *q) {
    int tmp = *p;
    *p = *q;
    *q = tmp;
  }
}
