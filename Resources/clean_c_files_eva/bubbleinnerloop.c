
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

int main(void)
{
    int a_var[4] = {1, 2, 3, 4};
    bubbleinnerloop(a_var, 42);
    return 0;
}
