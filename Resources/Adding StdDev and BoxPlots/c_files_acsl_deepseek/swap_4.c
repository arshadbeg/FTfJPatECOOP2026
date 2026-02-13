/*@
  requires \valid(a) && \valid(b);
  requires \separated(a, b);
  assigns *a, *b;
  ensures *a == \old(*b) && *b == \old(*a);
*/
void swap(int* a, int* b){
 int tmp = *a;
 *a = *b;
 *b = tmp;
 }
