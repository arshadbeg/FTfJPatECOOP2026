void reverse(int a[], int res[], int size)
{
	int i;
	
	for(i = size - 1; i >= 0; --i) {
		res[i] = a[size - i - 1];
	}
}

int main(void)
{
    int a_var[4] = {1, 2, 3, 4};
    int res_var[4] = {1, 2, 3, 4};
    reverse(a_var, res_var, 42);
    return 0;
}
