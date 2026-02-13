// Assume:
// char* s is a string of length n (n >= 0)
// int lastSpace is the index of the last space found, or -1 if none
// int lastBreak is the index after the last break (start of current line)
// int lineLength > 0
// int n is the length of s
// int indexOf(char*, int, int, int) returns index of char in substring or -1

//@ requires s != NULL;
//@ requires n >= 0;
//@ requires lastBreak >= 0;
//@ requires lastSpace == -1 || (lastSpace < n && s[lastSpace] == ' ');

//@ ensures For all positions in s[0..n-1], no substring between lastBreak and a space is longer than lineLength, except possibly at the end;
//@ ensures All spaces that would cause a line longer than lineLength have been replaced by '\n';

while (lastSpace != -1) {
  //@ invariant lastSpace != -1 ==> lastBreak <= lastSpace && lastBreak >= 0
  //@ invariant For all j. lastBreak < j < lastSpace ==> s[j] != ' ' 
  if (lastSpace - lastBreak > lineLength) {
    s[lastSpace] = '\n';
    lastBreak = lastSpace + 1; // or lastSpace, depending on whether you want the newline to start a new line after the space
    //@ assert After this, s[lastSpace] == '\n', and lastBreak is updated to start of new line
  }
  lastSpace = indexOf(s, ' ', lastBreak, n) - 1;
  //@ assert If found, lastSpace is index of next space after lastBreak; else -1
}
//@ assert Loop terminates when no more spaces are found after lastBreak
return;
