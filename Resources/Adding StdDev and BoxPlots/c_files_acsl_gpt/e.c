/*@
  ensures (0 <= i && i <= 9) ==> \result == (char)(i + '0');
  ensures !(0 <= i && i <= 9) ==> \result == ' ';
*/
char e(int i) {
  return (0 <= i && i <= 9) ? i + '0' : ' ';
}

