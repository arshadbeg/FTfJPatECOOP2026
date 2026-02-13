
/*@
  ensures (a==b && b==c) ==> \result==equilateral;
  ensures !(a==b && b==c) ==> \result==isoscele;
*/
enum type1 func1(int a,int b,int c){
	if(a==b && b==c) return equilateral;
	else if(a==b || b==c || c==a) return isoscele;
	else return scalene;
}
