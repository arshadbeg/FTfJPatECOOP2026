#include <stdio.h>

enum type1 {scalene, isoscele, equilateral};
enum type2 {right, acute, obtuse};

/*@
  requires a > 0 && b > 0 && c > 0;
  ensures (\result == equilateral) <==> (a==b && b==c);
  ensures (\result == isoscele) <==> ((a==b || b==c || c==a) && !(a==b && b==c));
  ensures (\result == scalene) <==> (a!=b && b!=c && c!=a);
*/
enum type1 func1(int a,int b,int c){
	if(a==b && b==c) return equilateral;
	else if(a==b || b==c || c==a) return isoscele;
	else return scalene;
}

/*@
  requires a > 0 && b > 0 && c > 0;
  ensures (\result == right) <==> (a*a == b*b + c*c);
  ensures (\result == acute) <==> (a*a < b*b + c*c);
  ensures (\result == obtuse) <==> (a*a > b*b + c*c);
*/
enum type2 func2(int a,int b,int c){
	// a is assumed hypotenuse
	if(a*a==b*b+c*c) return right;
	else if (a*a<b*b+c*c) return acute;
	else return obtuse;
}

