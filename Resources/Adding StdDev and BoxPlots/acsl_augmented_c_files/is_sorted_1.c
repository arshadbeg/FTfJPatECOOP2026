/*@
  ensures (a[i-1]>a[i]) ==> \result==0;
*/
int is_sorted(int a[],int n){
    
    /*@
	requires n>0;
	loop invariant 0<=i<=n-1;
	loop assigns i, ;
	loop variant n-1-i;
*/
for (int i=1;i<n;i++){
        if (a[i-1]>a[i]){
            return 0;
        }
    }
        return 1;
}