// ACSL annotation for opc.c
/*
@assigns rr;
@ensures rr == 9000;
*/

void opc() {
  rr = 9000; //@ ensures rr == 9000;
}
