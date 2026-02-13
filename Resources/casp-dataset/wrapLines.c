/*@  requires 0 < length;
  @  requires 0 < n < 2147483646; // the length of array is limited to MAX_INT -1 because of an overflow
  @  requires \valid(s+(0..n-1));
  @  ensures replace_space_by_new_line{Pre,Post}(s,n);
  @  ensures impossible_to_break(s,length,n);
  @  ensures break_largest{Pre,Post}(s, length, n);
  @  assigns s[0 .. n-1];
  @*/
void wrapLines(char* s, int length, int n) {