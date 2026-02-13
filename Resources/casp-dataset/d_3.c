/*@
assigns \nothing;
ensures -1<=\result<=9;
ensures d(c)==\result;
*/
int d(char c) {
  return ('0' <= c && c <= '9') ? c - '0' : -1;
}