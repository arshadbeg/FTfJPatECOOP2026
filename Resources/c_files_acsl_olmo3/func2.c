/*
  @ requires a > 0;
  @ requires b > 0;
  @ requires c > 0;
  @ ensures 
      \result == right   <==> a*a == b*b + c*c
      && 
      \result == acute   <==> a*a < b*b + c*c
      && 
      \result == obtuse  <==> a*a > b*b + c*c;
*/
enum type2 func2(int a, int b, int c) {
  // since a is assumed as hypotenuse
  if (a * a == b * b + c * c) return right;
  else if (a * a < b * b + c * c) return acute;
  else return obtuse;
}
