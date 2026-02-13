/*@ predicate break_largest{L1,L2}(char* s, int length, int n) =
  @   \forall int a, b, c; 0 <= a < b < c < n &&
  @   (a == -1 || \at(s[a],L2) == '\n') &&
  @   \at(s[b],L2) == '\n' && \at(s[b],L1) == ' ' &&
  @   (\at(s[c],L2) == ' ' || \at(s[c],L2) == '\n') ==>
  @   c - a > length;
*/