/*@ requires size >= 0;
    requires \valid(u + (0..size-1)) || size == 0;
    assigns \nothing;
    ensures \result == \max(0, \max_i(0 <= i < size, u[i]));
    ensures size > 0 ==> \exists integer i; 0 <= i < size && \result == u[i];
    ensures size > 0 ==> \forall integer i; 0 <= i < size ==> u[i] <= \result;
*/
int maxarray(int u[], int size) {
    int i = 1;
    max = 0;
}
