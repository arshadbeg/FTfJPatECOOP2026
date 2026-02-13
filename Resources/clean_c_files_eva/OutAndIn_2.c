void OutAndIn(int *i, int *o) {
  *o = *i;
}

int main(void)
{
    int i_var = 42;
    int o_var = 42;
    OutAndIn(&i_var, &o_var);
    return 0;
}
