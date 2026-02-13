/*@ requires n >= 0;
    requires \valid(a + (0..n-1));
    assigns \nothing;
    ensures \result == 1 <==> \forall integer i; 0 <= i < n-1 ==> a[i] <= a[i+1];
    ensures \result == 0 <==> \exists integer i; 0 <= i < n-1 && a[i] > a[i+1];
*/
int is_sorted(int a[],int n){
    
    /*@ loop invariant 1 <= i <= n;
        loop invariant \forall integer j; 1 <= j < i ==> a[j-1] <= a[j];
        loop assigns i;
        loop variant n - i;
    */
    for (int i=1;i<n;i++){
        if (a[i-1]>a[i]){
            return 0;
        }
    }
    return 1;
}
