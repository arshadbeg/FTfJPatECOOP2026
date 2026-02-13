/*@ 
  requires a != \null;
  requires 0 <= k < n;
  requires n > 1;
  assigns a[0..n-1];
  ensures \forall integer j; 0 <= j <= k ==> a[j] <= a[j+1] || \old(a[j] == a[j]);
*/
void q2(int a[], int n, int k) {
    for (int j = 0; j < k; j++) {
        if (a[j] > a[j+1]) {
            int t = a[j];
            a[j] = a[j+1];
            a[j+1] = t;
        }
    }
}

