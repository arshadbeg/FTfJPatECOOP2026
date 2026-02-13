
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
}