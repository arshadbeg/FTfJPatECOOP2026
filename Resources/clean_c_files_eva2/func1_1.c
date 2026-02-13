enum type1 func1(int a,int b,int c){
	if(a==b && b==c) return equilateral;
	else if(a==b || b==c || c==a) return isoscele;
	else return scalene;
}

int main(void)
{
    
    func1(0, 0, 0);
    return 0;
}
