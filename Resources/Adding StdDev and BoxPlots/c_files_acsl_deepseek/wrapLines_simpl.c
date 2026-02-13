/*@
  requires \valid(s+(0..n-1));
  requires lineLength > 0;
  assigns s[0..n-1];
  ensures \forall integer i; 0 <= i < n ==> 
    (s[i] == '\n' ==> 
      (\exists integer j; i+1 <= j < n && (j-i) > lineLength && s[j] == ' '));
*/
void wrapLines_simpl(char* s, int lineLength, int n) {
