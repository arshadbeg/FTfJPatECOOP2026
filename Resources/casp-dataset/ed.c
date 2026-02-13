/*@
assigns \nothing;
ensures '0'<=c<='9' ==> \result==c;
ensures c!=\result ==> \result==' ';
ensures e(d(c))==\result;
*/
char ed(char c) {
  return e(d(c));
}