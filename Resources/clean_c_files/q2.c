
void q2(int a[],int n,int k)
{

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