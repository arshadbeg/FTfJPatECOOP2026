/*@ requires \valid_function(gimmeOne);
    ensures \result == 0;
*/
int main() {
  int x = gimmeOne();
}
