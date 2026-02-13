/*@ requires n >= 0;
    requires \valid(t + (0..n-1)) || n == 0;
    assigns \nothing;
    ensures n > 0 ==> 0 <= \result < n;
    ensures n > 0 ==> \forall integer i; 0 <= i < n ==> t[\result] <= t[i];
    ensures n == 0 ==> \result == 0; // Default return for empty array
*/
int min(int * t, int n) {
  int minInd = 0, i =0;
}
