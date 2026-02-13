/*@ 
  requires s != \null;
  requires 0 <= lastSpace && lastSpace < n;
  requires n > 0;
  assigns s[0..n-1];
  ensures \forall integer i; 0 <= i < n ==> s[i] == \old(s[i]) || s[i] == '\n';
*/
void wrap_lines_spaces(char* s, int n, int lastSpace, int lastBreak, int lineLength) {
    while(lastSpace != -1) {
        if(lastSpace - lastBreak > lineLength) {
            s[lastSpace] = '\n';
            lastBreak = lastSpace;
        }
        lastSpace = indexOf(s, ' ', lastSpace+1, n);
    }
}

