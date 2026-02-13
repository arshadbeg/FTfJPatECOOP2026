void OutAndIn(int *i, int *o) {
  *o = *i;
}

int main(void)
{
    int i_var = 0;
    int o_var = 0;
    OutAndIn(&i_var, &o_var);
    return 0;
}
