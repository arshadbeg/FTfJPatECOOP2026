/*
  @ requires c is defined;
  @ ensures \result == (if ('0' <= c && c <= '9') then c - '0' else -1);
*/
int d(char c) {
  return ('0' <= c && c <= '9') ? c - '0' : -1;
}
