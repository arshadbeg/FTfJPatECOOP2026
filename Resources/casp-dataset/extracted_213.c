loop variant n-1-i;
     */
    while(i<n-1)
      if (t[++i] < t[minInd])
	minInd = i;
    //@ assert i == n-1;
    return minInd;
}