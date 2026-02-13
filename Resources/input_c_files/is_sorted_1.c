int is_sorted(int a[],int n){
    /*@
        loop invariant \forall integer j;
            1<=j<i ==> a[j]>=a[j-1];
        loop invariant 1<= i <= n;
        loop assigns i;
        loop variant n-i;
    */
    for (int i=1;i<n;i++){
        if (a[i-1]>a[i]){
            return 0;
        }
    }
        return 1;
}