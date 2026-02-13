/*@
  requires \valid(s+(0..n-1));
  requires length > 0;
  assigns s[0..n-1];
  ensures \forall integer i; 0 <= i < n ==> 
    (s[i] == '\n' ==> 
      (\exists integer j; i+1 <= j < n && (j-i) > length && s[j] == ' '));
*/
void wrapLines(char* s, int length, int n) {
