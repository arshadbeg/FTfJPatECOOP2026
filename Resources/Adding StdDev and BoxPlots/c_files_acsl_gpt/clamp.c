/*@
  requires min <= max;
  ensures min <= \result <= max;
  ensures \result == v || \result == min || \result == max;
*/
int clamp(int v, int min, int max)
{
  int low = v > min ? v : min;
  return low < max ? low : max;
}

