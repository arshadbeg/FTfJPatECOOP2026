/*@ requires p <= r;
    requires \valid(A + (p..r));
    assigns A[p..r];
    ensures p <= \result <= r;
    ensures \forall integer k; p <= k < \result ==> A[k] <= A[\result];
    ensures \forall integer k; \result < k <= r ==> A[k] >= A[\result];
    ensures \forall integer k1,k2; p <= k1 < \result < k2 <= r ==> A[k1] <= A[k2];
    ensures A[\result] == \old(A[r]);
*/
int partition (int A[], int p, int r) 
{ 
    int x = A[r]; 
    int tmp, j, i = p-1;
}
