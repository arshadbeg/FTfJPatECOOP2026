/*@
  ensures ('0' <= c && c <= '9') ==> \result == c - '0';
  ensures !('0' <= c && c <= '9') ==> \result == -1;
*/
int d(char c) {
  return ('0' <= c && c <= '9') ? c - '0' : -1;
}

