#include<stdio.h>
enum type1 {scalene,isoscele,equilateral};
enum type2 {right,acute,obtuse};

/*@
  ensures (a==b && b==c) ==> \result==equilateral;
  ensures !(a==b && b==c) ==> \result==isoscele;
*/
enum type1 func1(int a,int b,int c){
	if(a==b && b==c) return equilateral;
	else if(a==b || b==c || c==a) return isoscele;
	else return scalene;
}

/*@
  ensures (a*a==b*b+c*c) ==> \result==right;
  ensures !(a*a==b*b+c*c) ==> \result==acute;
*/
enum type2 func2(int a,int b,int c){
	//since a is assumed as hypotenuse
	if(a*a==b*b+c*c) return right;
	else if (a*a<b*b+c*c) return acute;
	else return obtuse;
}