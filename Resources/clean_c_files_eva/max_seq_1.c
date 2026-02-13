
int max_seq(unsigned int *t, int len) {
  if (len <= 0) return -1;
  return t[max_idx(t, len)];
}

int main(void)
{
    unsigned int t_var = 10U;
    max_seq(&t_var, 42);
    return 0;
}
