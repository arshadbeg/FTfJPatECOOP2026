/*
  @ requires a is defined;
  @ requires b is defined;
  @ requires c is defined;
  @ requires a > 0;
  @ requires b > 0;
  @ requires c > 0;
  @ ensures 
      \result == equilateral  <==> (a == b && b == c)
      && 
      \result == isoscele    <==> ((a == b) || (b == c) || (c == a)) && !(a == b && b == c)
      && 
      \result == scalene     <==> (a != b && b != c && c != a);
*/
enum type1 func1(int a, int b, int c) {
  if (a == b && b == c) return equilateral;
  else if (a == b || b == c || c == a) return isoscele;
  else return scalene;
}

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
  if (a * a == b * b + c * c) return right;
  else if (a * a < b * b + c * c) return acute;
  else return obtuse;
}
