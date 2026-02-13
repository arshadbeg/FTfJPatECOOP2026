/*@ requires \valid(&rr);
    assigns rr;
    ensures rr == \old(rr) + 1;
*/
void opa() {
  rr++;
}
