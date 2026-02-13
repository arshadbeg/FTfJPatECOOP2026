/*@ loop invariant -1 <= lastSpace < n;
    @ loop invariant -1 <= lastBreak < n;
    @ loop invariant lastSpace == -1 || (lastBreak < lastSpace < n && s[lastSpace] == ' ');
    @ loop invariant \forall int i; lastBreak < i < n ==> \at(s[i], LoopEntry) == s[i];
    @ loop invariant replace_space_by_new_line{LoopEntry,Here}(s,n);
    @ loop invariant at_least_lineLength(s,lineLength,n);
    @ loop assigns s[0..n-1],lastBreak,lastSpace;
    @ loop variant lastSpace == -1 ? 0 : n + 1 - lastSpace;
    @*/
  while(lastSpace != -1) {
    if(lastSpace - lastBreak > lineLength) {
      s[lastSpace] = '\n';
      lastBreak = lastSpace;
    }
    lastSpace = indexOf(s, ' ', lastSpace+1, n);
  }
  return;
}