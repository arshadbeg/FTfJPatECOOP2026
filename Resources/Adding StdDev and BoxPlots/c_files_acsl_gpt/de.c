/*@ 
  requires \exists integer r; \true;  // e is assumed total
  ensures \result == d(e(i));
*/
int de(int i) {
  return d(e(i));
}

