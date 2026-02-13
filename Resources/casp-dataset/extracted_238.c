/*@ predicate impossible_to_break(char* s, int length, int n) =
  @   \forall int i; 0 <= i < n - length ==>
  @   (\forall int j; i <= j <= i + length ==> s[j] != '\n') ==>
  @   (\forall int j; i <= j <= i + length ==> s[j] != ' ');
*/