
void max_ptr(int*p, int*q) { 
  if (*p > *q) { 
    int tmp = *p; 
    *p = *q; 
    *q = tmp; 
  } 
}

int main(void)
{
    int p_var = 0;
    int q_var = 0;
    max_ptr(&p_var, &q_var);
    return 0;
}
