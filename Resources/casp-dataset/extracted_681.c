/*@ predicate allequ{L}(integer i, int *x, integer res) =
  @ \forall integer j; (i <= j <= res+i-1) ==> (\at(x[i], L)==\at(x[j], L));
  @*/
//Examines equality between between all elemnts in [i,i+res-1]