/*@ 
  requires r != \null && i != \null && j != \null;
  assigns *r;
  ensures *r == (*i < *j ? *j : *i);
  ensures \result == -1 <==> r == \null;
*/
int max2(int *r, int* i, int* j) {
    if (!r) return -1;
    *r = (*i < *j) ? *j : *i;
    return 0;
}

