
int index_where(int* v, int n, int* o) {
  int r = 0;
  
  for (int i = 0; i < n; i++) {
    if (predicate(v[i])) {
      o[r++] = i;
    }
  }
  return r;
}