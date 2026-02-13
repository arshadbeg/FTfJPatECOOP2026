#include<stdio.h>
enum type1 {scalene,isoscele,equilateral};
enum type2 {right,acute,obtuse};

enum type1 func1(int a,int b,int c){
	if(a==b && b==c) return equilateral;
	else if(a==b || b==c || c==a) return isoscele;
	else return scalene;
}

enum type2 func2(int a,int b,int c){
	//since a is assumed as hypotenuse
	if(a*a==b*b+c*c) return right;
	else if (a*a<b*b+c*c) return acute;
	else return obtuse;
}