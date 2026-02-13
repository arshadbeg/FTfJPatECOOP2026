/*@ requires \valid(u+(0..size-1)) && 0 < size;
  @ ensures 0 <= \result < size &&
  @     (\forall integer a; 0 <= a < size ==> u[a] <= u[\result]);
  @ assigns max; 
  @*/
int maxarray(int u[], int size) {
    int i = 1;
    max = 0;