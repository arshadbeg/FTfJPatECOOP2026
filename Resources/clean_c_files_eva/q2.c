
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
    int a_var[4] = {1, 2, 3, 4};
    q2(a_var, 42, 42);
    return 0;
}
