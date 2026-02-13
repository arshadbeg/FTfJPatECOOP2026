/*@
  ensures (j-i > best) ==> \result==best;
*/
int countSameConsecutive(int N, int x[]) {
	int best = 0, i = 0;
	// we try to maintain an essence of current best in order to reach total (best)
	// for that we replace N <- i+1 (to look until i array positions)
	
	/*@
	requires N>0;
	loop invariant 0<=i<=N-1;
	loop assigns i, ;
	loop variant N-1-i;
*/
while (i < N) {
		int j = i+1;
		// while we are inside the second loop everything allequ for j-i 
		// (starting from i) matrix positions is maintained
		
		/*@
	loop invariant 0<=i<=None-1;
	loop invariant \forall integer i; 0<=i<i ==> x[i] >= x[i];
	loop assigns i, x[0..i+1];
*/
while (j < N && x[j] == x[i]) ++j;
		if (j-i > best) best = j-i;
		i = j;
	}
	return best;
}