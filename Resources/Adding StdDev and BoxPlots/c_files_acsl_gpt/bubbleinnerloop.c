/*@
  requires n >= 0;
  requires \valid(a + (0 .. n-1));
  assigns a[0 .. n-1];
  ensures \forall integer k; 0 <= k < n-1 ==> a[k] <= a[k+1] || \old(a[k]) <= \old(a[k+1]);
*/
void bubbleinnerloop(int a[], int n)
{
  /*@
    loop invariant 0 <= j <= n-1;
    loop invariant \forall integer k; 0 <= k < j ==> a[k] <= a[k+1];
    loop assigns j, a[0 .. n-1];
    loop variant n - 1 - j;
  */
  for (int j = 0; j < n - 1; j++)
  {
    if (a[j] > a[j + 1])
    {
      int temp = a[j];
      a[j] = a[j + 1];
      a[j + 1] = temp;
    }
  }
}

