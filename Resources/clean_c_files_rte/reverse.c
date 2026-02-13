
void reverse(int a[], int res[], int size)
{
	int i;
	
	for(i = size - 1; i >= 0; --i) {
		res[i] = a[size - i - 1];
	}
}