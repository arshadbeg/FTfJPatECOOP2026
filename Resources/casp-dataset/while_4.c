/*@ loop invariant -1 <= lastSpace < n;
    @ loop invariant -1 <= lastChange <= lastSpace;
    @ loop invariant lastSpace <= lastChange + length + 1;
    @ loop invariant lastChange == -1 || s[lastChange] == '\n';
    @ loop invariant 0 <= lastSpace  ==> \at(s[\at(lastSpace,Here)],LoopEntry) == ' ' || \at(s[\at(lastSpace,Here)],LoopEntry) == '\n';
    @ loop invariant \forall int x; lastChange < x < n ==> s[x] == \at(s[x],LoopEntry);
    @ loop invariant \forall int x; lastChange < x <= lastSpace ==> s[x] != '\n';
    @ loop invariant replace_space_by_new_line{LoopEntry,Here}(s,n);
    @ loop invariant impossible_to_break(s, length, lastSpace);
    @ loop invariant \forall int a, b, c; 0 <= a < b < c < n &&
        b <= lastChange && (a == -1 || s[a] == '\n') &&
        s[b] == '\n' && \at(s[b],LoopEntry) == ' ' &&
        (s[c] == ' ' || s[c] == '\n') ==> c - a > length;
    @ loop assigns s[0 .. n-1],lastChange, lastSpace;
    @ loop variant 2*n - lastSpace - lastChange;
    @*/
  while(1) {
    int nextSpace = indexOf(s, ' ', lastSpace + 1,n);
    int nextNewLine = indexOf(s, '\n', lastSpace + 1,n);
    if(nextSpace == -1) {
      /*n - lastChange can overflow if the array contain no space and is of size MAX_INT*/
      if(n - lastChange > length &&
	 (nextNewLine - lastChange > length || nextNewLine == -1) &&
	 lastSpace >= 0) {
	s[lastSpace] = '\n';
      }
      return;
    }