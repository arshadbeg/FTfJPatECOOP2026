/*@ predicate at_least_lineLength(char* s, int lineLength, int n) =
  @   \forall int i,j; 0 <= i < j < n && s[i] == '\n' && s[j] == '\n' ==> j-i >= lineLength;
*/