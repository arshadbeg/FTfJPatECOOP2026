/*@
  requires a != \null;
  requires n >= 0;
  requires \valid_read(a + (0 .. n-1));
  assigns \nothing;
  ensures \result == 1 <==> (\forall integer i; 1 <= i < n ==> a[i-1] <= a[i]);
  ensures \result == 0 <==> (\exists integer i; 1 <= i < n && a[i-1] > a[i]);
*/
int is_sorted(int a[], int n) {
    for (int i = 1; i < n; i++) {
        if (a[i-1] > a[i]) {
            return 0;
        }
    }
    return 1;
}

