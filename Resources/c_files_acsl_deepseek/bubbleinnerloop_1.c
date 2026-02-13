/*@ requires n >= 1;
    requires \valid(a + (0..n-1));
    assigns a[0..n-1];
    ensures \forall integer i; 0 <= i < n-1 ==> a[i] <= a[i+1]; // adjacent pairs are ordered
*/
void bubbleinnerloop(int a[], int n)
{
    /*@ loop invariant 0 <= j <= n-1;
        loop invariant \forall integer i; 0 <= i < j ==> a[i] <= a[i+1];
        loop invariant \forall integer k; j <= k < n-1 ==> \at(a[k], Pre) <= a[k+1];
        loop assigns j, a[0..n-1];
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
