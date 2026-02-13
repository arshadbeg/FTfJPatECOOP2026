/*@ predicate is_pos(int  x0) = (x0>0);*/
/*@
assigns \nothing;
ensures \result <==> is_pos(x0);
*/
int is_pos(int  x0) {
  int x2 = x0 > 0;
  return x2;
}
/*@ predicate is_nat(int  x3) = (x3>=0);*/
/*@
assigns \nothing;
ensures \result <==> is_nat(x3);
*/