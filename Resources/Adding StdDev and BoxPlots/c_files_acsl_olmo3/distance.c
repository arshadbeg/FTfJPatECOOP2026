/*
  @ requires -\infty < a;
  @ requires -\infty < b;
  @ ensures \result == |a - b|;
  @ ensures \result >= 0;
*/
int distance(int a, int b) {
  if (a < b)
    return b - a;
  else
    return a - b;
}
