
int index_where(int* v, int n, int* o) {
  int r = 0;
  
  for (int i = 0; i < n; i++) {
    if (predicate(v[i])) {
      o[r++] = i;
    }
  }
  return r;
}

int main(void)
{
    int v_var = 42;
    int o_var = 42;
    index_where(&v_var, 42, &o_var);
    return 0;
}
