/*@
  requires n >= 0;
  requires \valid(a + (0 .. n-1));
  assigns a[0 .. n-1];
*/
void bubbleinnerloop(int a[], int n)
{
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

