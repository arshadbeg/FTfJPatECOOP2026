
  while(lastSpace != -1) {
    if(lastSpace - lastBreak > lineLength) {
      s[lastSpace] = '\n';
      lastBreak = lastSpace;
    }
    lastSpace = indexOf(s, ' ', lastSpace+1, n);
  }
  return;
}