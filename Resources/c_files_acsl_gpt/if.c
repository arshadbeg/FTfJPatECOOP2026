/*@
  requires s != \null;
  requires 0 <= lastChange <= lastSpace < nextNewLine < nextSpace;
  requires \valid(s + (0 .. nextSpace));
  assigns s[0 .. nextSpace], lastChange, lastSpace;
*/
void handle_line_breaks(char* s, int lastChange, int lastSpace, int nextNewLine, int nextSpace, int length) {
  if(0 <= nextNewLine && nextNewLine < nextSpace) {
    if(nextNewLine - lastChange > length && lastSpace >= 0) {
      s[lastSpace] = '\n';
    }
    lastChange = lastSpace = nextNewLine;
  } else {
    if(nextSpace - lastChange > length) {
      if(lastChange == lastSpace) {
        s[nextSpace] = '\n';
        lastChange = lastSpace = nextSpace;
      } else {
        s[lastSpace] = '\n';
        lastChange = lastSpace;
      }
    } else {
      lastSpace = nextSpace;
    }
  }
}

