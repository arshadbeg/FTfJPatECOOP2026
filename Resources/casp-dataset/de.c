/*@
assigns \nothing;
ensures 0<=i<=9 ==> \result==i;
ensures i!=\result ==> \result==-1;
ensures d(e(i))==\result;
*/
int de(int i) {
  return d(e(i));
}