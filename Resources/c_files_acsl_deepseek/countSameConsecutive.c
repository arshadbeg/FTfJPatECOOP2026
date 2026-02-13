/*@ requires N >= 0;
    requires \valid(x + (0..N-1));
    assigns \nothing;
    ensures 0 <= \result <= N;
    ensures \result == 0 <==> N == 0;
    ensures \forall integer i; 0 <= i <= N-\result ==> 
            (\exists integer k; i <= k < i+\result && x[k] != x[i]) || 
            \result == 0;
*/
int countSameConsecutive(int N, int x[]) {
    int best = 0, i = 0;
    
    /*@ loop invariant 0 <= i <= N;
        loop invariant 0 <= best <= N;
        loop invariant best == 0 || \exists integer k; 0 <= k <= i-best && 
                (\forall integer m; k <= m < k+best ==> x[m] == x[k]);
        loop invariant i == 0 || \forall integer k; 0 <= k < i ==> 
                (\exists integer m; k <= m < i && x[m] != x[k]) || 
                x[k] == x[i-1];
        loop assigns i, best;
        loop variant N-i;
    */
    while (i < N) {
        int j = i+1;
        
        /*@ loop invariant i+1 <= j <= N;
            loop invariant \forall integer k; i <= k < j ==> x[k] == x[i];
            loop assigns j;
            loop variant N-j;
        */
        while (j < N && x[j] == x[i]) ++j;
        
        if (j-i > best) best = j-i;
        i = j;
    }
    return best;
}
