/*@ requires 0 <= p <= r && \valid(A+(p..r));
  @*/
int partition (int A[], int p, int r) 
{ 
  int x = A[r]; 
  int tmp, j, i = p-1;