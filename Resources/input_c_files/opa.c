/*@ requires rr<50;
  @ behavior j :
  @  ensures rr<51;
*/
void opa() {
  rr++;
}