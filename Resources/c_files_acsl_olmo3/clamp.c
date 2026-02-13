/*
  @ requires min <= max;
  @ ensures \result == v || \result == min || \result == max;
  @ ensures min <= \result && \result <= max;
  @ ensures 
      ((v <= min) ==> \result == min) 
      && 
      ((v >= max) ==> \result == max) 
      && 
      ((min < v && v < max) ==> \result == v);
*/
int clamp(int v, int min, int max) {
    int low = v > min ? v : min;
    return low < max ? low : max;
}
