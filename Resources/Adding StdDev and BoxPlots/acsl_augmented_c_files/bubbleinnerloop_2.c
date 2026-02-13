void bubbleinnerloop(int a[], int n)
{
	
	/*@
	loop invariant 0<=i<=None-1;
	loop assigns i, ;
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