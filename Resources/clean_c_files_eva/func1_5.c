
enum type1 func1(int a,int b,int c){
	if(a==b && b==c) return equilateral;
	else if(a==b || b==c || c==a) return isoscele;
	else return scalene;
}

int main(void)
{
    
    func1(42, 42, 42);
    return 0;
}
