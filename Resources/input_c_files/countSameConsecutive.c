/*@ requires N > 0;
  @ requires \valid(x + (0..N-1));
  @ ensures  cond(N, x,\result);
  @*/
int countSameConsecutive(int N, int x[]) {
	int best = 0, i = 0;
	// we try to maintain an essence of current best in order to reach total (best)
	// for that we replace N <- i+1 (to look until i array positions)
	/*@ loop invariant 0 <= i <= N;
      @ loop invariant 0 <= best <= N;
      @ loop invariant 0 < i <==> 0 < best;
      @ loop invariant (0 < best <==> allequ(i,x,best)) || (best == 0 <==> i==0) ;
      @ loop invariant (0 < best <==> ismax(i,x,best,i+1)) || (best == 0 <==> i==0);
      @ loop invariant ((0 < i < N && 0 < best) <==> cond(i+1,x,best)) || (best == 0 <==> i==0);
      @ loop assigns i, best;
      @ loop variant N-i;
     @*/
	while (i < N) {
		int j = i+1;
		// while we are inside the second loop everything allequ for j-i 
		// (starting from i) matrix positions is maintained
		/*@ loop invariant i+1 <= j <= N;
          @ loop invariant (x[j] == x[i]) ==> allequ(i,x,j-i);
          @ loop assigns j;
          @ loop variant N-j;
          @*/
		while (j < N && x[j] == x[i]) ++j;
		if (j-i > best) best = j-i;
		i = j;
	}
	return best;
}