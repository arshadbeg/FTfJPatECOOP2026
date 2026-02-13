/*@
  requires \valid(a + (0..n-1));
  requires 0 < k < n;
  assigns a[0..k];
  ensures \forall integer i; 0 <= i < k ==> a[i] <= a[i+1];
*/
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
