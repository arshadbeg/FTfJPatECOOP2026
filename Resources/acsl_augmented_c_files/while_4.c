
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