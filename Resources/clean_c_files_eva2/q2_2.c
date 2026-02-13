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

int main(void)
{
    int a_var[1] = {0};
    q2(a_var, 0, 0);
    return 0;
}
