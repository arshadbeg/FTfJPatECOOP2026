
void q2(int a[],int n,int k)
{

	/*@
	loop invariant 0<=i<=None-1;
	loop assigns i, ;
*/
for (int j=0;j<k;j++)
	{
		if(a[j]>a[j+1])
		{
			int t=a[j];
			a[j]=a[j+1];
			a[j+1]=t;
		}
	}
}