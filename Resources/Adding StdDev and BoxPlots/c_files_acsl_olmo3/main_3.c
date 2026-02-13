/*
  @ ensures \result == 0;
  @ ensures \exists int x; x == gimmeOne() && x == 1;
*/
int main() {
  int x = gimmeOne();
  return 0;
}
