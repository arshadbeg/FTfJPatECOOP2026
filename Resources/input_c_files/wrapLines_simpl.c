/*@  requires lineLength > 0;
  @  requires 0 < n;
  @  requires \valid(s+(0..n-1));
  @  requires \forall int i; 0 <= i < n ==> s[i] != '\n';
  @  ensures replace_space_by_new_line{Pre,Post}(s,n);
  @  ensures at_least_lineLength(s,lineLength,n);
  @  assigns s[0 .. n -1];
  @*/
void wrapLines_simpl(char* s, int lineLength, int n) {