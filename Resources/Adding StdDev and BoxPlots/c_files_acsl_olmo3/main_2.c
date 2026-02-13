/*
  @ ensures \old(a) == 14 && \old(b) == 13;
  @ ensures \result == 0;
  @ assume requires swap(int *p1, int *p2) ensures *p1 == \old(*p2) && *p2 == \old(*p1);
*/
int main() {
    int a = 13;
    int b = 14;
    swap(&a, &b);
    return 0;
}
