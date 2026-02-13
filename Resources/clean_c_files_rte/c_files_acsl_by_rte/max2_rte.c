[kernel] Warning: no input file.
[kernel] Parsing max2.c (with preprocessing)
[kernel] Warning: end of file reached before line 5
[kernel] max2.c:4: 
  syntax error:
  Location: between lines 4 and 5, before or at token: 
  2     int max2(int *r, int* i, int* j) {
  3     if (!r) return -1;
  
  4     *r = (*i < *j) ? *j : *i;
[kernel] Frama-C aborted: invalid user input.
