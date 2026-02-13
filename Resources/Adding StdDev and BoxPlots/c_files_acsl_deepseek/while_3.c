/*@
  loop invariant -1 <= lastSpace <= n;
  loop invariant -1 <= lastBreak <= n;
  loop invariant lastBreak <= lastSpace;
  loop invariant \valid(s+(0..n-1));
  loop assigns lastSpace, lastBreak, s[0..n-1];
  loop variant lastSpace;
*/
while(lastSpace != -1) {
    if(lastSpace - lastBreak > lineLength) {
      s[lastSpace] = '\n';
      lastBreak = lastSpace;
    }
    lastSpace = indexOf(s, ' ', lastSpace+1, n);
  }
  return;
}
