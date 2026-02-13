
int pick_element(int* p, int n) {
  int i = pick_index(n);
  
  return p[i];
}

int main(void)
{
    int p_var = 42;
    pick_element(&p_var, 42);
    return 0;
}
