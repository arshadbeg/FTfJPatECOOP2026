/*@
  requires a > 0 && b > 0 && c > 0;
  ensures (\result == right) <==> (a*a == b*b + c*c);
  ensures (\result == acute) <==> (a*a < b*b + c*c);
  ensures (\result == obtuse) <==> (a*a > b*b + c*c);
*/
enum type2 func2(int a,int b,int c){
	if(a*a==b*b+c*c) return right;
	else if (a*a<b*b+c*c) return acute;
	else return obtuse;
}

