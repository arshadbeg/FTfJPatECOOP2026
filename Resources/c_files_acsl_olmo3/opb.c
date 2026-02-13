// ACSL annotation for opb.c
/*
@assigns status;
@ensures status == 1;
*/

void opb() {
  status = 1; //@ ensures status == 1;
}
