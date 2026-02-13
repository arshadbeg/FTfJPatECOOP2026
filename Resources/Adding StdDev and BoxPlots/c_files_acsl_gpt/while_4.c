/*@ 
  requires s != \null;
  requires n > 0 && length > 0;
  requires 0 <= lastChange && lastChange < n;
  assigns s[0..n-1];
  ensures \forall integer i; 0 <= i < n ==> s[i] == \old(s[i]) || s[i] == '\n';
*/
void wrap_lines_spaces_and_newlines(char* s, int length, int lastSpace, int lastChange, int n) {
    while(1) {
        int nextSpace = indexOf(s, ' ', lastSpace + 1,n);
        int nextNewLine = indexOf(s, '\n', lastSpace + 1,n);
        if(nextSpace == -1) {
            if(n - lastChange > length &&
               (nextNewLine - lastChange > length || nextNewLine == -1) &&
               lastSpace >= 0) {
                s[lastSpace] = '\n';
            }
            return;
        }
        // loop continues...
    }
}

