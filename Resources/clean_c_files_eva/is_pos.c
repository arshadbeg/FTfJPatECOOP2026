#include <limits.h>


int is_pos(int  x0) {
  int x2 = x0 > 0;
  return x2;
}


int is_nat(int  x3) {
  int x5 = x3 >= 0;
  return x5;
}

int minus1(int  x6) {
  int x8 = x6 - 1;
  return x8;
}

int main(void)
{
    
    is_pos(42);
    return 0;
}
