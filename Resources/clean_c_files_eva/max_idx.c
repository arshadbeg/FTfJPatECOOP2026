
int max_idx(unsigned int *t, int len) {
  int max = 0;
  
  for(int i = 1; i < len; i++)
    if (t[max] < t[i])
      max = i;
  return max;
}

int main(void)
{
    unsigned int t_var = 10U;
    max_idx(&t_var, 42);
    return 0;
}
