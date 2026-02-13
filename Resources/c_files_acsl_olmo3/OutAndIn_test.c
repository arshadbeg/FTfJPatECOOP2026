/*
  @ requires i != NULL;
  @ requires o != NULL;
  @ ensures *o == *i;
*/
void OutAndIn(int *i, int *o) {
  *o = *i;
}
