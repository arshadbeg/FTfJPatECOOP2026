/*@ loop invariant p <= j <= r;
    loop invariant \forall integer k; p <= k < j ==> (k <= i ==> A[k] <= x) && (k > i ==> A[k] > x);
    loop invariant p-1 <= i < j;
    loop invariant \forall integer k; p <= k <= i ==> A[k] <= x;
    loop invariant \forall integer k; i < k < j ==> A[k] > x;
    loop assigns j, i, A[p..r];
    loop variant r - j;
*/
for(j=p; j<r; j++) 
    if (A[j] <= x) { 
        i++; 
        tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
    } 
tmp = A[i+1];
A[i+1] = A[r];
A[r] = tmp;
return i+1;
