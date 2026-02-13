/*@ predicate cond{L}(integer N, int *x, integer res) =
  @   \exists integer i; (0 <= i < N-res) ==> (allequ(i,x,res) && ismax(i,x,res,N));
  @*/
//For something to satisfy the given condition there must exist an integer such that for i to
// i+res-1 positions we will have equality and this will be the max length