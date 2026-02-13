void inswap(int  * x0, int  x1, int  x2) {
  int x4 = x0[x1];
  int x5 = x0[x2];
  x0[x1] = x5;
  x0[x2] = x4;
}

int main(void)
{
    int x0_var = 0;
    inswap(&x0_var, 0, 0);
    return 0;
}
