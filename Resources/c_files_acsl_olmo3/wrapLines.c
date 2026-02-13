/*@ 
  requires s != \null;
  requires n >= 0 && lineLength > 0;
  assigns s[0..n-1];
  ensures \forall integer i; 0 <= i < n ==> s[i] == \old(s[i]) || s[i] == '\n';
*/
void wrapLines(char* s, int length, int n);

/*@ 
  requires s != \null;
  requires n >= 0 && lineLength > 0;
  assigns s[0..n-1];
  ensures \forall integer i; 0 <= i < n ==> s[i] == \old(s[i]) || s[i] == '\n';
*/
void wrapLines_simpl(char* s, int lineLength, int n);

