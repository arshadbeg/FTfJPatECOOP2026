/*@ predicate ismax{L}(integer i, int *x, integer res,integer N) =
  @   \forall integer j; (0 < j <= N-1 && j!=i) ==> (\forall integer rp; (1 < rp < N && allequ(j,x,rp)) ==> (rp <= res));
  @*/
//Examines that res is the max res the you can get in length N
//For every r that satisfies allequ this r must be smaller-equal from res