int max2(int *r, int* i, int* j) {
if (!r) return -1;
*r = (*i < *j) ? *j : *i;