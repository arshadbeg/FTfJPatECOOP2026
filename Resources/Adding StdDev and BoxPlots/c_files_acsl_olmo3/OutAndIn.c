/*
  @ requires i != NULL;
  @ requires o != NULL;
  @ ensures *o == \old(*i); // or just *o == *i if you want to assume no change to *i
*/
void OutAndIn(int *i, int *o) {
  *o = *i;
}
