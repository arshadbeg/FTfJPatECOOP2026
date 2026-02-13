/*@
assigns \nothing;
ensures '0'<=\result<='9' || \result==' ';
ensures e(i)==\result;
*/
char e(int i) {
  return (0 <= i && i <= 9) ? i + '0' : ' ';
}