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

