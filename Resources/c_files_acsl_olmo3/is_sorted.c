/*
  @ requires a != NULL;
  @ requires n >= 0;
  @ ensures \result == 1 <==> \forall integer i; 0 <= i < n - 1 ==> a[i] <= a[i+1];
  @ ensures \result == 0 <==> \exists integer i; 0 <= i < n - 1 && a[i] > a[i+1];
*/
int is_sorted(int a[], int n) {
    for (int i = 1; i < n; i++) {
        if (a[i-1] > a[i]) {
            return 0;
        }
    }
    return 1;
}
