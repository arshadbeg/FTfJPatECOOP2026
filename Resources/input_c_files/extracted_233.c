/*@ predicate replace_space_by_new_line{L1,L2}(char* s, int n) =
  @   \forall int i; 0 <= i < n && \at(s[i], L1) != \at(s[i],L2) ==>
  @   \at(s[i], L1) == ' ' && \at(s[i],L2) == '\n';
*/