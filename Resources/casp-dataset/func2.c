enum type2 func2(int a,int b,int c){
	//since a is assumed as hypotenuse
	if(a*a==b*b+c*c) return right;
	else if (a*a<b*b+c*c) return acute;
	else return obtuse;
}