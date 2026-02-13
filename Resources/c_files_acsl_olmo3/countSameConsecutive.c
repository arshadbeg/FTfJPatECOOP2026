/*
  @ requires x != NULL;
  @ requires N >= 0;
  @ ensures \result == 
      (\max_{integer i, l} l | 0 <= i < N - l + 1 && \forall integer j; 0 <= j < l ==> x[i + j] == x[i]);
  // Or in ACSL's expressible subset:
  @ ensures \result == 
      (\max_{integer i; 0 <= i < N} 
         (\let l = 0;
           \while { i + l < N && x[i + l] == x[i] } l := l + 1;
           l
         ));
  // But ACSL does not support while in logic, so we can write a postcondition that for all i, the run length starting at i is at most \result, and that there exists an i with run length == \result.
  @ ensures \forall integer i, l;
      0 <= i < N - l + 1 ==> 
          (\forall integer j; 0 <= j < l ==> x[i + j] == x[i]) 
          ==> l <= \result;
  @ ensures \exists integer i, l;
      0 <= i < N - l + 1 && 
      (\forall integer j; 0 <= j < l ==> x[i + j] == x[i]) && 
      l == \result;
*/
int countSameConsecutive(int N, int x[]) {
    int best = 0, i = 0;
    while (i < N) {
        int j = i + 1;
        while (j < N && x[j] == x[i]) ++j;
        if (j - i > best) best = j - i;
        i = j;
    }
    return best;
}
