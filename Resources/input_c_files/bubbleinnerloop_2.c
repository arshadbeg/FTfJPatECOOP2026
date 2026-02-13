void bubbleinnerloop(int a[], int n)
{
	/*@
	loop invariant\forall integer i;
	0<= i<j ==> a[j]>=a[i];loop invariant 0<=j<=n-1;
	loop assigns j,a[0..j+1];
	loop variant n-1-j;
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