int countSameConsecutive(int N, int x[]) {
	int best = 0, i = 0;
	// we try to maintain an essence of current best in order to reach total (best)
	// for that we replace N <- i+1 (to look until i array positions)
	
	while (i < N) {
		int j = i+1;
		// while we are inside the second loop everything allequ for j-i 
		// (starting from i) matrix positions is maintained
		
		while (j < N && x[j] == x[i]) ++j;
		if (j-i > best) best = j-i;
		i = j;
	}
	return best;
}