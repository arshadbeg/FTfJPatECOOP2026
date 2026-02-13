/*@ requires \valid(i) && \valid(j);
    ensures \result == -1 <==> r == \null;
    ensures \result == 0 <==> r != \null;
    behavior valid_r:
      assumes r != \null;
      requires \valid(r);
      assigns *r;
      ensures *r >= *i && *r >= *j;
      ensures *r == *i || *r == *j;
      ensures (*i < *j) ==> *r == *j;
      ensures (*i >= *j) ==> *r == *i;
    behavior invalid_r:
      assumes r == \null;
      assigns \nothing;
      ensures \result == -1;
*/
int max2(int *r, int* i, int* j) {
    if (!r) return -1;
    *r = (*i < *j) ? *j : *i;
}
