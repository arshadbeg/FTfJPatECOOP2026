/*@ ensures ('0' <= c && c <= '9') ==> 0 <= \result <= 9;
    ensures !('0' <= c && c <= '9') ==> \result == -1;
    ensures ('0' <= c && c <= '9') ==> \result == c - '0';
    assigns \nothing;
*/
int d(char c) {
  return ('0' <= c && c <= '9') ? c - '0' : -1;
}
